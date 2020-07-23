/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:58:35 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/11 16:58:37 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	int		i;
	int		l;

	d = (char*)dst;
	s = (char*)src;
	i = 0;
	l = (int)len - 1;
	if (dst == src)
		return (dst);
	else if (dst > src)
	{
		l = l + 1;
		while ((--l) != -1)
			d[l] = s[l];
		return (dst);
	}
	else
	{
		i = i - 1;
		while ((++i) <= l)
			d[i] = s[i];
		return (dst);
	}
}
