/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:46:11 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/09 14:46:13 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char*)haystack;
	s2 = (char*)needle;
	if (needle[0] == '\0')
		return (s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return (s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
