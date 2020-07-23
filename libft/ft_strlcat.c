/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:02:02 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/21 13:04:11 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ldst;
	size_t lsrc;
	size_t i;
	size_t end;

	i = 0;
	ldst = ft_strlen(dst);
	end = ldst;
	lsrc = ft_strlen(src);
	if (size <= ldst)
		return (lsrc + size);
	while ((src[i] != '\0') && (end < (size - 1)))
	{
		dst[end] = src[i];
		end++;
		i++;
	}
	dst[end] = '\0';
	return (ldst + lsrc);
}
