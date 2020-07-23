/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:18:31 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/20 16:48:52 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1);
	if (ft_strlen(s1) < ft_strlen(s2))
		len = ft_strlen(s2);
	while ((s1[i] == s2[i] && s1[i] && s2[i]) || len)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
		len--;
	}
	return (1);
}
