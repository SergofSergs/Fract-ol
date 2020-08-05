/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   khook.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:57:53 by oem               #+#    #+#             */
/*   Updated: 2020/08/05 16:38:57 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int key, t_mlx *mlx)
{
	char *s1;
	char *s2;

	s1 = ft_itoa(key);
	s2 = ft_strjoin(s1, "\n");
	if (key == 53)
	{
		free(mlx);
		exit(0);
	}
	ft_putstr(s2);
	free(s1);
	free(s2);
	if (key == 8)
		controls(mlx);
	return (0);
}

void	controls(t_mlx *mlx)
{
	int		posx;
	char	*s1;
	char	*s2;

	s1 = ft_itoa(mlx->itt_max);
	s2 = ft_strjoin("Max_itterations: ", s1);
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
	mlx_string_put(mlx->ptr, mlx->win, 10, \
		posx * 4, 0x000000, "Zoom with the mouse wheel");
	mlx_string_put(mlx->ptr, mlx->win, 10, \
		posx * 5, 0xFF0000, s2);
	free(s1);
	free(s2);
}

int		mouse_hook(int key, int x, int y, t_mlx *mlx)
{
	if (key == 4)
		zoom(x, y, mlx);
	if (key == 5)
		unzoom(x, y, mlx);
	return (0);
}
