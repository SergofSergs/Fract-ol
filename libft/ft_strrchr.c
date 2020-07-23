/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:22:16 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/09 14:22:19 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ch;
	int		len;

	str = (char*)s;
	ch = (char)c;
	len = ft_strlen(str);
	while (len != -1)
	{
		if (str[len] == ch)
			return (str + len);
		len--;
	}
	return (NULL);
}
