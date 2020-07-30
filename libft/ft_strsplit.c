/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:37:31 by pjoseth           #+#    #+#             */
/*   Updated: 2020/02/04 18:42:58 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				countwords(const char *s, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && (s[i + 1]))
			word++;
		i++;
	}
	if (s[0] != '\0')
		word++;
	return (word);
}

static	char	*fill(const char *s, char c, int *i)
{
	char	*new;
	int		j;

	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s)))))
		return (NULL);
	j = 0;
	while (s[*i] != c && s[*i])
	{
		new[j] = s[*i];
		j++;
		(*i)++;
	}
	new[j] = '\0';
	while (s[*i] == c && s[*i])
		(*i)++;
	return (new);
}

static void		freewords(char **new, int *j)
{
	while (*j != -1)
	{
		free(new[*j]);
		(*j)--;
	}
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		word;
	char	**new;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	word = countwords(s, c);
	if (!(new = (char **)malloc(sizeof(new) * (countwords(s, c) + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < word && s[i])
	{
		if (!(new[j] = fill(s, c, &i)))
		{
			freewords(new, &j);
			return (NULL);
		}
		j++;
	}
	new[j] = NULL;
	return (new);
}
