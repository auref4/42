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

#include <mlx.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <X11/keysymdef.h>
#include <X11/keysym.h>

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
}				t_vars;

typedef struct	s_fract {
	long double	x1;
	long double	x2;
	long double	y1;
	long double	y2;
	int	image_x;
	int	image_y;
	long double zoom_x;
	long double zoom_y;
	int	x;
	int	y;
	long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	int	i;
	int	i_max;
	long double tmp;
}				t_fract;

void	error(int nb);
int		check_arg(char **argv);
void	fractol(int nb);
void	create_win_img(t_vars *vars, t_data *img, int nb);
int		closer(t_vars *vars);
int		mouse_hook(int keycode, t_fract *fract);
void	value_mandelbrot(t_fract *fract);
void	value_julia(t_fract *fract);
void	calcul_mandelbrot(t_fract fract, t_data *img, t_vars *vars);
void	calcul_julia(t_fract fract, t_data *img, t_vars *vars);
void	calcul_julia_2(t_fract fract, t_data *img, t_vars *vars);
void	calcul_julia_3(t_fract fract, t_data *img, t_vars *vars);
void	create_fractal(t_fract fract, t_data *img, t_vars *vars, int nb);
void	color_mandelbrot(t_fract fract, t_data *img);
void	color_julia(t_fract fract, t_data *img);

# endif
