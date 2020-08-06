/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:37:03 by pjoseth           #+#    #+#             */
/*   Updated: 2020/08/06 17:39:11 by pjoseth          ###   ########.fr       */
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
	mlx->itt_max = 90;
	mlx->min_re = -2;
	mlx->max_re = 2.2;
	mlx->min_im = -1.2;
	mlx->k_re = -0.4;
	mlx->k_im = 0.6;
	mlx->max_im = mlx->min_im + \
		(((mlx->max_re - mlx->min_re) * HEIGHT) / WIDTH);
	mlx->zoom = 1;
	return (mlx);
}

void	fractal_thr(t_mlx *mlx)
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
		if (mlx->fract == 1)
			pthread_create(&thread[i], NULL, mandelbrot, &xlm[i]);
		if (mlx->fract == 2)
			pthread_create(&thread[i], NULL, julia, &xlm[i]);
		i++;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
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
	fractal_thr(mlx);
	controls(mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	if (mlx->fract == 2)
		mlx_hook(mlx->win, 6, 0, julia_m, mlx);
	mlx_loop(mlx->ptr);
	return (1);
}
