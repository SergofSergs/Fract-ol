/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:09:13 by pjoseth           #+#    #+#             */
/*   Updated: 2020/07/22 23:25:11 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str;
	unsigned char	*rts;

	str = (unsigned char*)s1;
	rts = (unsigned char*)s2;
	while (*str == *rts && *str && *rts)
	{
		str++;
		rts++;
	}
	return (*str - *rts);
}
