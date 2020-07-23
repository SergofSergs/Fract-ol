/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:38:30 by oem               #+#    #+#             */
/*   Updated: 2020/07/23 23:04:01 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <pthread.h>
# include <math.h>
# define WIDTH 960
# define HEIGHT 640
# define ITT 255

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	unsigned char	*img_data;
	int				fract;
	int				bpp;
	int				size_line;
	int				endian;
	double			L;
}					t_mlx;

int					ret(int code, t_mlx *mlx);
int					name_check(char *str);
int					get_color(double x, double y);
void				mandelbrot(t_mlx *mlx);

#endif