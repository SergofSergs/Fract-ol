/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:00:50 by pjoseth           #+#    #+#             */
/*   Updated: 2020/08/11 17:20:55 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_text(int posx, int posy, char *s2, t_mlx *mlx)
{
	int	n;

	n = 17;
	mlx_string_put(mlx->ptr, mlx->win, posx + 150, posy, 0xFFFFFF, "MENU");
	mlx_string_put(mlx->ptr, mlx->win, posx, \
		posy + n, 0xFFFFFF, "Exit the programm: ESC");
	mlx_string_put(mlx->ptr, mlx->win, posx, \
		posy + n * 2, 0xFFFFFF, "Zoom with the mouse wheel");
	mlx_string_put(mlx->ptr, mlx->win, posx, posy + n * 3, \
		0xFFFFFF, "Move around with the arrow keys");
	mlx_string_put(mlx->ptr, mlx->win, posx, \
		posy + n * 4, 0xFFFFFF, "Reset position: r");
	mlx_string_put(mlx->ptr, mlx->win, posx, \
		posy + n * 5, 0xFFFFFF, "Increase or decrease itterations: * and /");
	mlx_string_put(mlx->ptr, mlx->win, posx, \
		posy + n * 6, 0xFFFFFF, "Change color: Page up");
	mlx_string_put(mlx->ptr, mlx->win, posx, \
		posy + n * 7, 0xFFFFFF, "Open this menu again: c");
	mlx_string_put(mlx->ptr, mlx->win, posx, posy + n * 8, \
		0xFFFFFF, "In Julia only you can stop/start mouse tracking with: s/g");
	mlx_string_put(mlx->ptr, mlx->win, posx, posy + n * 9, \
		0xFFFFFF, "TO CONTINUE PRESS r OR ANYTHING MENTIONED ABOVE ;)");
	mlx_string_put(mlx->ptr, mlx->win, posx, \
		posy + n * 10, 0xFF0000, s2);
}

void	color_switch(int key, t_mlx *mlx)
{
	if (mlx->img != NULL)
	{
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->img = NULL;
	}
	if (key == 116)
	{
		mlx->c_num += 1;
		mlx->c_num = mlx->c_num % 3;
	}
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_data = (unsigned char*)mlx_get_data_addr(mlx->img, \
		&mlx->bpp, &mlx->size_line, &mlx->endian);
	fractal_thr(mlx);
}

int		which_color(int color, int counter, t_mlx *mlx)
{
	if (mlx->c_num == 0)
		color = get_ultra(counter);
	if (mlx->c_num == 2)
		color = 0x000F00 * counter;
	return (color);
}

int		get_color_7_15(int n, int color)
{
	if (n == 7)
		color = 209 + (125 * 0x10 * 0x10) + (57 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 8)
		color = 229 + (181 * 0x10 * 0x10) + (134 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 9)
		color = 248 + (236 * 0x10 * 0x10) + (211 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 10)
		color = 191 + (233 * 0x10 * 0x10) + (241 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 11)
		color = 95 + (201 * 0x10 * 0x10) + (248 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 12)
		color = 0 + (170 * 0x10 * 0x10) + (255 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 13)
		color = 0 + (128 * 0x10 * 0x10) + (204 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 14)
		color = 0 + (87 * 0x10 * 0x10) + (153 * 0x10 * 0x10 * 0x10 * 0x10);
	if (n == 15)
		color = 3 + (52 * 0x10 * 0x10) + (106 * 0x10 * 0x10 * 0x10 * 0x10);
	return (color);
}

void	calc_arrows(double re, double im, int key, t_mlx *mlx)
{
	if (key == 123)
	{
		mlx->max_re -= re * 0.05;
		mlx->min_re -= re * 0.05;
	}
	if (key == 124)
	{
		mlx->max_re += re * 0.05;
		mlx->min_re += re * 0.05;
	}
	if (key == 125)
	{
		mlx->max_im -= im * 0.05;
		mlx->min_im -= im * 0.05;
	}
	if (key == 126)
	{
		mlx->max_im += im * 0.05;
		mlx->min_im += im * 0.05;
	}
}
