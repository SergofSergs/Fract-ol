/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:38:30 by oem               #+#    #+#             */
/*   Updated: 2020/07/24 17:58:31 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <pthread.h>
# include <math.h>
# define WIDTH 1280
# define HEIGHT 720
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
	int				color;
	int				x0;
	int				y0;
	double			l;
}					t_mlx;

int					ret(int code, t_mlx *mlx);
int					name_check(char *str);
int					get_color(double x, double y, int color);
void				mandelbrot(t_mlx *mlx);
int					key_hook(int key, t_mlx *mlx);
void				zoom(int key, t_mlx *mlx);
void				controls(t_mlx *mlx);
t_mlx				*mlx_initial(char *str);

#endif
