/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:59:14 by pjoseth           #+#    #+#             */
/*   Updated: 2020/08/11 17:23:22 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		calculate_bs(double co_re, double co_im, int color, t_mlx *mlx)
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
		x1 = fabs((re * re) - (im * im) + co_re);
		y1 = -2 * fabs(re * im) + co_im;
		counter++;
	}
	if (counter == mlx->itt_max)
		color = 0x000000;
	return (color);
}

void	*burning_ship(void *xlm)
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
			mlx->color = calculate_bs(get_core(i, mlx), \
				get_coim(j, mlx), mlx->color, mlx);
			ft_memcpy(mlx->img_data + mlx->size_line * j + i * 4, \
				&mlx->color, sizeof(int));
			j++;
		}
		i++;
	}
	return (xlm);
}
