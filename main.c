/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:37:03 by pjoseth           #+#    #+#             */
/*   Updated: 2020/07/24 18:00:44 by oem              ###   ########.fr       */
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
	mlx->l = 320.0;
	mlx->x0 = (3 * WIDTH) / 4;
	mlx->y0 = HEIGHT / 2;
	return (mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		color;

	mlx = NULL;
	color = 0xF3F3F3;
	if (argc != 2)
		return (ret(1, mlx));
	if (!(mlx = mlx_initial(argv[1])))
		return (0);
	if (!(mlx->fract = name_check(argv[1])))
		return (ret(2, mlx));
	mandelbrot(mlx);
	controls(mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_loop(mlx->ptr);
	return (1);
}
