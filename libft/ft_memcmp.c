/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:53:25 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/11 19:53:27 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str;
	unsigned char *rts;

	str = (unsigned char*)s1;
	rts = (unsigned char*)s2;
	while (n)
	{
		if (*str != *rts)
			return (*str - *rts);
		if (n)
		{
			str++;
			rts++;
		}
		n--;
	}
	return (0);
}
