/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:31:17 by pjoseth           #+#    #+#             */
/*   Updated: 2020/08/06 17:40:35 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double start, double end, double interp)
{
	double new;

	new = start + ((end - start) * interp);
	return (new);
}

void	calculate_new_pos(double mouse_re, \
	double mouse_im, double interp, t_mlx *mlx)
{
	mlx->min_re = interpolate(mouse_re, mlx->min_re, interp);
	mlx->max_re = interpolate(mouse_re, mlx->max_re, interp);
	mlx->min_im = interpolate(mouse_im, mlx->min_im, interp);
	mlx->max_im = interpolate(mouse_im, mlx->max_im, interp);
}

void	zoom(double x, double y, t_mlx *mlx)
{
	double mouse_re;
	double mouse_im;
	double interp;

	mouse_re = x / (WIDTH / (mlx->max_re - mlx->min_re)) + mlx->min_re;
	mouse_im = y / (HEIGHT / (mlx->max_im - mlx->min_im)) \
		* -1 + mlx->max_im;
	if (mlx->img != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->zoom = 1.1;
	interp = 1.0 / mlx->zoom;
	calculate_new_pos(mouse_re, mouse_im, interp, mlx);
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_data = (unsigned char*)mlx_get_data_addr(mlx->img, \
		&mlx->bpp, &mlx->size_line, &mlx->endian);
	if (mlx->itt_max < 9000000000000000000)
		mlx->itt_max *= 1.10;
	fractal_thr(mlx);
}

void	unzoom(double x, double y, t_mlx *mlx)
{
	double mouse_re;
	double mouse_im;
	double interp;

	mouse_re = x / (WIDTH / (mlx->max_re - mlx->min_re)) + mlx->min_re;
	mouse_im = y / (HEIGHT / (mlx->max_im - mlx->min_im)) \
		* -1 + mlx->max_im;
	if (mlx->img != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->zoom = 0.9;
	interp = 1.0 / mlx->zoom;
	calculate_new_pos(mouse_re, mouse_im, interp, mlx);
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_data = (unsigned char*)mlx_get_data_addr(mlx->img, \
		&mlx->bpp, &mlx->size_line, &mlx->endian);
	if (mlx->itt_max > 20)
		mlx->itt_max /= 1.10;
	fractal_thr(mlx);
}
