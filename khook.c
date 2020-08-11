/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   khook.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:57:53 by oem               #+#    #+#             */
/*   Updated: 2020/08/11 17:18:41 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		free(mlx);
		exit(0);
	}
	if (key == 116)
		color_switch(key, mlx);
	if (key == 8)
		controls(mlx);
	if (key == 15)
		restore_pos(mlx);
	if (key == 1 || key == 5)
		julia_stop(key, mlx);
	if (key == 75 || key == 67)
		itterations(key, mlx);
	if (key == 126 || key == 123 || key == 125 || key == 124)
		arrows_move(key, mlx);
	return (0);
}

void	controls(t_mlx *mlx)
{
	int		posx;
	int		posy;
	char	*s1;
	char	*s2;

	s1 = ft_itoa(mlx->itt_max);
	s2 = ft_strjoin("Max_itterations: ", s1);
	posx = WIDTH * 3 / 8;
	posy = HEIGHT / 3;
	if (mlx->img != NULL)
	{
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx->img = NULL;
	}
	put_text(posx, posy, s2, mlx);
	free(s1);
	free(s2);
}

void	restore_pos(t_mlx *mlx)
{
	if (mlx->img != NULL)
	{
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->img = NULL;
	}
	mlx->itt_max = 50;
	mlx->min_re = -2;
	mlx->max_re = 2.2;
	mlx->min_im = -1.2;
	mlx->max_im = mlx->min_im + \
		(((mlx->max_re - mlx->min_re) * HEIGHT) / WIDTH);
	mlx->zoom = 1;
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_data = (unsigned char*)mlx_get_data_addr(mlx->img, \
		&mlx->bpp, &mlx->size_line, &mlx->endian);
	fractal_thr(mlx);
}

void	itterations(int key, t_mlx *mlx)
{
	if (mlx->img != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img);
	if (key == 75 && mlx->itt_max >= 50)
		mlx->itt_max /= 1.5;
	if (key == 67 && mlx->itt_max <= 1000)
		mlx->itt_max *= 1.5;
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_data = (unsigned char*)mlx_get_data_addr(mlx->img, \
		&mlx->bpp, &mlx->size_line, &mlx->endian);
	fractal_thr(mlx);
}

void	arrows_move(int key, t_mlx *mlx)
{
	double	re;
	double	im;

	if (mlx->img != NULL)
	{
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->img = NULL;
	}
	re = fabs(mlx->max_re - mlx->min_re);
	im = fabs(mlx->max_im - mlx->min_im);
	calc_arrows(re, im, key, mlx);
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_data = (unsigned char*)mlx_get_data_addr(mlx->img, \
		&mlx->bpp, &mlx->size_line, &mlx->endian);
	fractal_thr(mlx);
}
