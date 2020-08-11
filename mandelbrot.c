/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:25:06 by oem               #+#    #+#             */
/*   Updated: 2020/08/11 17:22:16 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_ultra(int itt)
{
	int		color;
	int		n;

	color = 0x000000;
	if (itt == 0)
		return (color);
	n = itt % 16;
	if (n == 0)
		color = 15 + (30 * 0x10 * 0x10) + (66 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 1)
		color = 26 + (7 * 0x10 * 0x10) + (25 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 2)
		color = 47 + (1 * 0x10 * 0x10) + (9 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 3)
		color = 73 + (4 * 0x10 * 0x10) + (4 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 4)
		color = 100 + (7 * 0x10 * 0x10) + (0 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 5)
		color = 138 + (44 * 0x10 * 0x10) + (12 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 6)
		color = 177 + (82 * 0x10 * 0x10) + (24 * 0x10 * 0x10 * 0x10 * 0x10);
	color = get_color_7_15(n, color);
	return (color);
}

int		calculate_m(double x, double y, int color, t_mlx *mlx)
{
	int		counter;
	double	x1;
	double	y1;
	double	re;
	double	im;

	counter = 0;
	x1 = x;
	y1 = y;
	while (counter < mlx->itt_max)
	{
		re = x1;
		im = y1;
		if (sqrt((x1 * x1) + (y1 * y1)) > 2)
			return (which_color(color, counter, mlx));
		if (mlx->c_num == 1 && color)
			color -= 0x010101;
		x1 = (re * re) - (im * im) + x;
		y1 = (2 * re * im) + y;
		counter++;
	}
	if (counter == mlx->itt_max)
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

void	*mandelbrot(void *xlm)
{
	t_mlx	*mlx;
	int		i;
	int		j;

	mlx = (t_mlx*)xlm;
	i = 0;
	while (i < WIDTH)
	{
		j = mlx->y_start;
		while (j < mlx->y_max)
		{
			mlx->color = 0xFFFFFF;
			mlx->color = calculate_m(get_core(i, mlx), \
				get_coim(j, mlx), mlx->color, mlx);
			ft_memcpy(mlx->img_data + mlx->size_line * j + i * 4, \
				&mlx->color, sizeof(int));
			j++;
		}
		i++;
	}
	return (xlm);
}
