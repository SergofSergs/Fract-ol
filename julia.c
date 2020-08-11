/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:02:15 by pjoseth           #+#    #+#             */
/*   Updated: 2020/08/11 17:23:29 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		calculate_j(double co_re, double co_im, int color, t_mlx *mlx)
{
	int		counter;
	double	x1;
	double	y1;
	double	re;
	double	im;

	counter = 0;
	x1 = co_re;
	y1 = co_im;
	while (counter < mlx->itt_max)
	{
		re = x1;
		im = y1;
		if (sqrt((x1 * x1) + (y1 * y1)) > 2)
			return (which_color(color, counter, mlx));
		if (mlx->c_num == 1 && color)
			color -= 0x010101;
		x1 = (re * re) - (im * im) + mlx->k_re;
		y1 = (2 * re * im) + mlx->k_im;
		counter++;
	}
	if (counter == mlx->itt_max)
		color = 0x000000;
	return (color);
}

void	*julia(void *xlm)
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
			mlx->color = calculate_j(get_core(i, mlx), \
				get_coim(j, mlx), mlx->color, mlx);
			ft_memcpy(mlx->img_data + mlx->size_line * j + i * 4, \
				&mlx->color, sizeof(int));
			j++;
		}
		i++;
	}
	return (xlm);
}

int		julia_m(int x, int y, t_mlx *mlx)
{
	if (mlx->stop == 1)
		return (0);
	if (mlx->img != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->k_re = 4 * ((double)x / WIDTH - 0.5);
	mlx->k_im = 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_data = (unsigned char*)mlx_get_data_addr(mlx->img, \
		&mlx->bpp, &mlx->size_line, &mlx->endian);
	fractal_thr(mlx);
	return (0);
}

void	julia_stop(int key, t_mlx *mlx)
{
	if (key == 1)
		mlx->stop = 1;
	if (key == 5)
		mlx->stop = 0;
}
