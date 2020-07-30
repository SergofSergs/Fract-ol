/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:24:39 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/20 16:30:28 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				len;
	unsigned char	*str;
	unsigned char	*rts;

	i = 0;
	len = (int)n;
	str = (unsigned char*)s1;
	rts = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (str[i] == rts[i] && str[i] != '\0' && rts[i] != '\0' && n)
	{
		i++;
		n--;
	}
	if (!n)
		return (str[i - 1] - rts[i - 1]);
	return (str[i] - rts[i]);
}
