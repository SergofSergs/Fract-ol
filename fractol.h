/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:38:30 by oem               #+#    #+#             */
/*   Updated: 2020/08/04 20:50:47 by oem              ###   ########.fr       */
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
# define ITT_MAX 50
# define THR_W 10
# define THREADS (WIDTH / THR_W)

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
	int				y_start;
	int				y_max;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			zoom;
}					t_mlx;

int					ret(int code, t_mlx *mlx);
int					name_check(char *str);
int					get_color(double x, double y, int color);
void				*mandelbrot(void *xlm);
int					key_hook(int key, t_mlx *mlx);
void				controls(t_mlx *mlx);
t_mlx				*mlx_initial(char *str);
int					mouse_hook(int key, int x, int y, t_mlx *mlx);
void				mandelbrot_thr(t_mlx *mlx);

#endif
