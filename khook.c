/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   khook.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:57:53 by oem               #+#    #+#             */
/*   Updated: 2020/08/04 20:41:49 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int key, t_mlx *mlx)
{
	if (key == 65307)
	{
		free(mlx);
		exit(0);
	}
	ft_putstr(ft_strjoin(ft_itoa(key), "\n"));
	if (key == 99)
		controls(mlx);
	return (0);
}

void	controls(t_mlx *mlx)
{
	int posx;

	posx = 17;
	if (mlx->img != NULL)
	{
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->img = NULL;
	}
	mlx_string_put(mlx->ptr, mlx->win, 10, posx, 0x000000, "Controls");
	mlx_string_put(mlx->ptr, mlx->win, 10, \
		posx * 2, 0x000000, "Exit the programm: ESC");
	mlx_string_put(mlx->ptr, mlx->win, 10, \
		posx * 3, 0x000000, "Show controls: c");
}

double	interpolate(double start, double end, double interp)
{
	double new;

	new = start + ((end - start) * interp);
	return (new);
}

void	calculate_new_pos(double mouse_re, double mouse_im, double interp, t_mlx *mlx)
{
	mlx->min_re = interpolate(mouse_re, mlx->min_re, interp);
	mlx->max_re = interpolate(mouse_re, mlx->max_re, interp);
	mlx->min_im = interpolate(mouse_im, mlx->min_im, interp);
	mlx->max_im = interpolate(mouse_im, mlx->max_im, interp);
}

int		mouse_hook(int key, int x, int y, t_mlx *mlx)
{
	double mouse_re;
	double mouse_im;
	double interp;

	mouse_re = (double)x / (WIDTH / (mlx->max_re - mlx->min_re)) + mlx->min_re;
	mouse_im = (double)y / (HEIGHT / (mlx->max_im - mlx->min_im)) + mlx->min_im;
	if (key == 4)
	{
		if (mlx->img != NULL)
			mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->zoom *= 1.05;
		interp = 1.0 / mlx->zoom;
		calculate_new_pos(mouse_re, mouse_im, interp, mlx);
		mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
		mlx->img_data = (unsigned char*)mlx_get_data_addr(mlx->img, \
			&mlx->bpp, &mlx->size_line, &mlx->endian);
		mandelbrot_thr(mlx);

	}
	if (key == 5)
	{
		if (mlx->img != NULL)
			mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->zoom /= 1.05; 
		interp = 1.0 / mlx->zoom;
		calculate_new_pos(mouse_re, mouse_im, interp, mlx);
		mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
		mlx->img_data = (unsigned char*)mlx_get_data_addr(mlx->img, \
			&mlx->bpp, &mlx->size_line, &mlx->endian);
		mandelbrot_thr(mlx);
	}
	return (0);
}