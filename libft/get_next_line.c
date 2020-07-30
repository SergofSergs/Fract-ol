/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:12:38 by pjoseth           #+#    #+#             */
/*   Updated: 2020/01/04 17:08:18 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*s2;
	int		i;

	i = 0;
	if (!(s2 = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

t_list	*load(int fd, t_list **history)
{
	t_list *list;

	list = *history;
	while (list)
	{
		if ((int)list->content_size == fd)
			return (list);
		list = list->next;
	}
	if (!(list = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(history, list);
	return (list);
}

int		readline(int fd, char **str)
{
	char	*rts;
	int		readres;
	char	buf[BUFF_SIZE + 1];

	while ((readres = read(fd, buf, BUFF_SIZE)))
	{
		buf[readres] = '\0';
		rts = ft_strjoin(*str, buf);
		free(*str);
		*str = rts;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (readres);
}

int		copytoline(char **line, char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(*line = ft_strndup(str, i)))
		return (-1);
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	char			*str;
	char			buf[BUFF_SIZE + 1];
	static t_list	*history;
	t_list			*list;
	int				readres;

	if (fd < 0 || !line || read(fd, buf, 0) < 0
		|| !(list = load(fd, &history)) || BUFF_SIZE < 1)
		return (-1);
	str = list->content;
	if ((readres = readline(fd, &str)) == -1)
		return (-1);
	list->content = str;
	if (readres == 0 && !*str)
		return (0);
	if ((readres = copytoline(line, str)) == -1)
		return (-1);
	if (str[readres] != '\0')
	{
		list->content = ft_strdup(&((list->content)[readres + 1]));
		free(str);
	}
	else
		str[0] = '\0';
	return (1);
}
