/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:30:24 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/20 16:10:23 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*skip(const char *str, int *neg, int *count)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		str++;
		(*count)++;
	}
	str = str - (*count);
	return (str);
}

int					ft_atoi(const char *str)
{
	int				count;
	int				neg;
	long long int	result;
	long long int	buf;

	count = 0;
	neg = 1;
	result = 0;
	buf = 0;
	str = skip(str, &neg, &count);
	while (*str >= 48 && *str <= 57)
	{
		result = (result * 10) + (long long int)(*str - 48);
		if ((result / 10) != buf)
		{
			if (neg == 1 && count > 19)
				return (-1);
			return (0);
		}
		buf = result;
		str++;
	}
	return (result * neg);
}
