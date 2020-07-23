/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:16:06 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/19 17:00:45 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		lenght(long int n)
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

char			*ft_itoa(int n)
{
	long int	nb;
	char		*new;
	int			len;

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
