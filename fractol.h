/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:38:30 by oem               #+#    #+#             */
/*   Updated: 2020/08/11 17:21:34 by pjoseth          ###   ########.fr       */
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
# define THR_W 2
# define THREADS (HEIGHT / THR_W)

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
	int				itt_max;
	int				y_start;
	int				y_max;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			zoom;
	double			k_re;
	double			k_im;
	int				stop;
	int				c_num;
}					t_mlx;

t_mlx				*mlx_initial(char *str);
void				fractal_thr(t_mlx *mlx);

int					ret(int code, t_mlx *mlx);
int					name_check(char *str);

int					get_ultra(int itt);
int					calculate_m(double x, double y, int color, t_mlx *mlx);
double				get_core(int i, t_mlx *mlx);
double				get_coim(int j, t_mlx *mlx);
void				*mandelbrot(void *xlm);

int					key_hook(int key, t_mlx *mlx);
void				controls(t_mlx *mlx);
void				restore_pos(t_mlx *mlx);
void				itterations(int key, t_mlx *mlx);
void				arrows_move(int key, t_mlx *mlx);

int					mouse_hook(int key, int x, int y, t_mlx *mlx);
double				interpolate(double start, double end, double interp);
void				calculate_new_pos(double mouse_re,
	double mouse_im, double interp, t_mlx *mlx);
void				zoom(double x, double y, t_mlx *mlx);
void				unzoom(double x, double y, t_mlx *mlx);

int					calculate_j(double co_re, double co_im,
	int color, t_mlx *mlx);
void				*julia(void *xlm);
int					julia_m(int x, int y, t_mlx *mlx);
void				julia_stop(int key, t_mlx *mlx);

int					calculate_bs(double co_re, double co_im,
	int color, t_mlx *mlx);
void				*burning_ship(void *xlm);

void				put_text(int posx, int posy, char *s2, t_mlx *mlx);
void				color_switch(int key, t_mlx *mlx);
int					which_color(int color, int counter, t_mlx *mlx);
int					get_color_7_15(int n, int color);
void				calc_arrows(double re, double im, int key, t_mlx *mlx);

#endif
