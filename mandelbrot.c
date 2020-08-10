/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:25:06 by oem               #+#    #+#             */
/*   Updated: 2020/08/09 19:22:16 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(double abs_z, int itt)
{
	double				continuous_index;
	unsigned char		p1;
	unsigned char		p2;
	unsigned char		p3;
	int					color;

	color = 0x000000;
	continuous_index = itt + 1 - (log(2) / abs_z) / log(2);
	p1 = (unsigned char)(sin(0.016 * continuous_index + 4) * 230 + 25);
	p2 = (unsigned char)(sin(0.013 * continuous_index + 2) * 230 + 25);
	p3 = (unsigned char)(sin(0.01 * continuous_index + 1) * 230 + 25);
	color = p3 + (p2 * 0x10 * 0x10) + (p1 * 0x10 * 0x10 * 0x10 * 0x10);
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
		{
			color = get_color(sqrt((x1 * x1) + (y1 * y1)), counter);
			return (color);
		}
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
