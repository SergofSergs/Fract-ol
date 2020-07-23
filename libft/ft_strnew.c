/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:12:58 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/20 15:05:03 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *mem;

	if ((size + 1) < size)
		return (NULL);
	mem = (char*)malloc(sizeof(char) * (size + 1));
	if (!mem)
		return (NULL);
	ft_memset(mem, '\0', size + 1);
	return (mem);
}
