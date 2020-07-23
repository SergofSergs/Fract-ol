/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:25:06 by oem               #+#    #+#             */
/*   Updated: 2020/07/23 23:12:25 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(double x, double y)
{
	int		color;
	int		counter;
	double	x1;
	double	y1;
	double	re;
	double	im;

	counter = 0;
	color = 0xFFFFFF;
	x1 = x;
	y1 = y;
	while (counter < ITT && color)
	{
		re = x1;
		im = y1;
		if (sqrt((x1 * x1) + (y1 * y1)) > 2)
			return (color);
		color -= 0x010101;
		x1 = (re * re) - (im * im) + x;
		y1 =  (2 * re * im) + y;
		counter++;
	}
	return (color);
}

void	mandelbrot(t_mlx *mlx)
{
	int		i;
	int		j;
	double	x0;
	double	y0;
	int		color;

	i = 0;
	x0 = (3 * WIDTH) / 4;
	y0 = HEIGHT / 2;
	mlx->img_data = (unsigned char*)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			color = get_color((i - x0) / mlx->L, (j - y0) / mlx->L);
			ft_memcpy(mlx->img_data + mlx->size_line * j + i * 4, &color, sizeof(int));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_string_put(mlx->ptr, mlx->win, 0, 0, 0xFF0000, ft_strjoin("itterations - ", ft_itoa(ITT)));
}
