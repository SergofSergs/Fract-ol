/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:56:19 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/18 21:11:29 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const	*skip(char const *s, int *len)
{
	*len = ft_strlen(s);
	while (s[*len - 1] == ' ' || s[*len - 1] == '\t' || s[*len - 1] == '\n')
		(*len)--;
	while (*s == ' ' || *s == '\t' || *s == '\n')
	{
		(*len)--;
		s++;
	}
	return (s);
}

char				*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	s = skip(s, &len);
	if (len < 0)
		len = 0;
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = *s;
		i++;
		s++;
	}
	new[i] = '\0';
	return (new);
}
