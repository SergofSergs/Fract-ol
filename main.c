/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:37:03 by pjoseth           #+#    #+#             */
/*   Updated: 2020/07/23 23:16:56 by oem              ###   ########.fr       */
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
	ft_putstr(ft_strjoin(ft_itoa(key),"\n"));
	if (key == 65451)
	{
		mlx->L /= 0.9;
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
		mandelbrot(mlx); 
	}
	if (key == 65453)
	{
		mlx->L *= 0.9;
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
		mandelbrot(mlx); 
	}
	if (key == 65293)
		mandelbrot(mlx);
	return (0);
}

void	*ls_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (d == NULL && s == NULL)
		return (d);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		color;

	mlx = NULL;
	color = 0xF3F3F3;
	if (argc != 2)
		return(ret(1, mlx));
	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (0);
	if (!(mlx->fract = name_check(argv[1])))
		return(ret(2, mlx));
	mlx->L = 320.0;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, argv[1]);
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_loop(mlx->ptr);
	return (1);
}