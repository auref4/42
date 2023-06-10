/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:36:46 by auferran          #+#    #+#             */
/*   Updated: 2023/03/23 05:30:36 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_key(int keycode, t_vars *vars, t_fract fract)
{
	if (keycode == 4 || keycode == 5)
		mouse_hook(keycode, &fract);
	if (keycode == XK_Escape)
		closer(vars);
	return (0);
}

int	closer(t_vars *vars)
{
	mlx_loop_end ((*vars).mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	mouse_hook(int keycode, t_fract *fract)
{
	if (keycode == 4)
		(*fract).x1++;
	if (keycode == 5)
		(*fract).y2--;
	return (0);
}

void	create_win_img(t_vars *vars, t_data *img, int nb)
{
	vars->mlx = mlx_init();
	if (nb == 1)
		vars->win = mlx_new_window(vars->mlx, 800, 800, "Mandelbrot");
	else if (nb == 2)
		vars->win = mlx_new_window(vars->mlx, 800, 800, "Julia");
	else if (nb == 3)
		vars->win = mlx_new_window(vars->mlx, 800, 800, "Julia 2");
	else if (nb == 4)
		vars->win = mlx_new_window(vars->mlx, 800, 800, "Julia 3");
	img->img = mlx_new_image(vars->mlx, 800, 800);
	img->addr = (int *)mlx_get_data_addr(img->img,
		&img->bits_per_pixel, &img->line_length, &img->endian);
}


void	fractol(int nb)
{
	t_data	img;
	t_vars	vars;
	t_fract	fract;

	vars.mlx = NULL;
	vars.win = NULL;
	create_win_img(&vars, &img, nb);
	mlx_hook(vars.win, 2, 1L<<0, check_key, &vars);
	mlx_hook(vars.win, 17, 1L<<0, closer, &vars);
	mlx_mouse_hook(vars.win, check_key, &vars);
	create_fractal(fract, &img, &vars, nb);
	mlx_destroy_image(vars.mlx, img.img);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}
