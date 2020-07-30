/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:09:13 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/07 18:29:31 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*rts;

	i = 0;
	str = (unsigned char*)s1;
	rts = (unsigned char*)s2;
	while (*str == *rts && *str && *rts)
	{
		str++;
		rts++;
	}
	return (*str - *rts);
}
