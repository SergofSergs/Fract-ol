/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:16:06 by pjoseth           #+#    #+#             */
/*   Updated: 2020/08/05 17:01:14 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		lenght(long long int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(long long int n)
{
	long long int	nb;
	char			*new;
	int				len;

	nb = n;
	len = lenght(nb);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new[len] = '\0';
	len = len - 1;
	if (nb == 0)
		new[0] = '0';
	if (nb < 0)
	{
		new[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		new[len] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	return (new);
}
