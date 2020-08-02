/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   khook.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:57:53 by oem               #+#    #+#             */
/*   Updated: 2020/08/02 22:53:36 by oem              ###   ########.fr       */
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
