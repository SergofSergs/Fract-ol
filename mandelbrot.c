/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:25:06 by oem               #+#    #+#             */
/*   Updated: 2020/08/05 16:54:18 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(double x, double y, int color, unsigned long long itt_max)
{
	unsigned long long	counter;
	double				x1;
	double				y1;
	double				re;
	double				im;

	counter = 0;
	x1 = x;
	y1 = y;
	while (counter < itt_max && color)
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
	if (counter == itt_max)
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

void	mandelbrot_thr(t_mlx *mlx)
{
	pthread_t	thread[THREADS];
	t_mlx		xlm[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		ft_memcpy((void *)&xlm[i], (void*)mlx, sizeof(t_mlx));
		xlm[i].y_start = i * THR_W;
		xlm[i].y_max = (i + 1) * THR_W;
		pthread_create(&thread[i], NULL, mandelbrot, &xlm[i]);
		i++;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
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
			mlx->color = get_color(get_core(i, mlx), \
				get_coim(j, mlx), mlx->color, mlx->itt_max);
			ft_memcpy(mlx->img_data + mlx->size_line * j + i * 4, \
				&mlx->color, sizeof(int));
			j++;
		}
		i++;
	}
	return (xlm);
}
