/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:23:05 by auferran          #+#    #+#             */
/*   Updated: 2023/03/23 05:30:41 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define ZOOM 4
# define DEZOOM 5

# include <mlx.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/keysymdef.h>
# include <X11/keysym.h>

typedef struct	s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		keycode;
}				t_vars;

typedef struct	s_fract {
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			image_x;
	int			image_y;
	double		zoom_x;
	double		zoom_y;
	int			x;
	int			y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int			i;
	int			j;
	int			j_max;
	int			i_max;
	int			i_zoom;
	double		tmp;
	double		mouse_zoom_x;
	double		mouse_zoom_y;
	double		value_zoom;
	long double	move;
	int			check;
	int			check_2;

}				t_fract;

typedef struct	s_all {
	t_data	img;
	t_vars	vars;
	t_fract	fract;
	int		nb;
}				t_all;

void	error(int nb);
int		check_arg(char **argv);
int		fractol(int nb);
void	create_win_img(t_vars *vars, t_data *img, int nb);
int		closer(t_vars *vars);
void	init_hook(t_all *all);
int		mouse_hook(int keycode, int x, int y, t_all *all);
int		move_hook(int keycode, t_all *all);
void	value_mandelbrot(t_fract *fract);
void	value_julia(t_fract *fract);
void	calcul_mandelbrot(t_fract fract, t_data *img, t_vars *vars);
void	calcul_julia(t_fract fract, t_data *img, t_vars *vars);
void	calcul_julia_2(t_fract fract, t_data *img, t_vars *vars);
void	calcul_julia_3(t_fract fract, t_data *img, t_vars *vars);
void	create_fractal(t_fract fract, t_data *img, t_vars *vars, int nb);
void	color_mandelbrot(t_fract fract, t_data *img);
void	color_julia(t_fract fract, t_data *img);
void	color_julia_2(t_fract fract, t_data *img);
void	color_julia_3(t_fract fract, t_data *img);


# endif
