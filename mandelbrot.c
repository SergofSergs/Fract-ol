/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:25:06 by oem               #+#    #+#             */
/*   Updated: 2020/08/02 22:51:30 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(double x, double y, int color)
{
	int		counter;
	double	x1;
	double	y1;
	double	re;
	double	im;

	counter = 0;
	x1 = x;
	y1 = y;
	while (counter < ITT_MAX && color)
	{
		re = x1;
		im = y1;
		if (sqrt((x1 * x1) + (y1 * y1)) > 2)
			return (color);
		color -= 0x010101;
		x1 = (re * re) - (im * im) + x;
		y1 = (2 * re * im) + y;
		counter++;
	}
	if (counter == ITT_MAX)
		color = 0x000000;
	return (color);
}

double	get_core(int i, t_mlx *mlx)
{
	double co_re;

	co_re = mlx->min_re + (i * (mlx->max_re - mlx->min_re) / (WIDTH - 1));
	return (co_re);
}

double	get_coim(int j, t_mlx *mlx)
{
	double	co_im;

	co_im = mlx->max_im - (j * (mlx->max_im - mlx->min_im) / (HEIGHT - 1));
	return (co_im);
}

void	mandelbrot(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_data = (unsigned char*)mlx_get_data_addr(mlx->img, \
		&mlx->bpp, &mlx->size_line, &mlx->endian);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			mlx->color = 0xFFFFFF;
			mlx->color = get_color(get_core(i, mlx), \
				get_coim(j, mlx), mlx->color);
			ft_memcpy(mlx->img_data + mlx->size_line * j + i * 4, \
				&mlx->color, sizeof(int));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}
