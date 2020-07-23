/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 23:12:52 by oem               #+#    #+#             */
/*   Updated: 2020/07/22 23:30:34 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ret(int code, t_mlx *mlx)
{
	if (code == 1)
	{
		ft_putstr("Usage: ./fractol FRACTAL_NAME\n");
		ft_putstr("Avalible names: mandelbrot, julia and burning_ship\n");
		return (0);
	}
	if (code == 2)
		ft_putstr("Incorrect FRACTAL_NAME\n");
	free(mlx);
	return (0);
}

int		name_check(char *str)
{
	if (!(ft_strcmp(str, "mandelbrot")))
		return (1);
	if (!(ft_strcmp(str, "julia")))
		return (2);
	if (!(ft_strcmp(str, "burning_ship")))
		return (3);
	return (0);
}
