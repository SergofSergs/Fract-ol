/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:37:03 by pjoseth           #+#    #+#             */
/*   Updated: 2020/08/04 21:18:13 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*mlx_initial(char *str)
{
	t_mlx	*mlx;

	mlx = NULL;
	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, str);
	mlx->min_re = -2;
	mlx->max_re = 2.2;
	mlx->min_im = -1.2;
	mlx->max_im = mlx->min_im + \
		(((mlx->max_re - mlx->min_re) * HEIGHT) / WIDTH);
	mlx->zoom = 1;
	return (mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = NULL;
	if (argc != 2)
		return (ret(1, mlx));
	if (!(mlx = mlx_initial(argv[1])))
		return (0);
	if (!(mlx->fract = name_check(argv[1])))
		return (ret(2, mlx));
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_data = (unsigned char*)mlx_get_data_addr(mlx->img, \
		&mlx->bpp, &mlx->size_line, &mlx->endian);
	mandelbrot_thr(mlx);
	controls(mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_loop(mlx->ptr);
	return (1);
}
