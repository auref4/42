/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:36:46 by auferran          #+#    #+#             */
/*   Updated: 2023/06/21 16:50:38 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_hook(t_all *all)
{
	(void) all;
	all->fract.j = 1;
	all->fract.j_max = 3;
	all->fract.check = 0;
	all->fract.check_2 = 0;
	all->fract.move = 0.02;
	all->fract.mouse_zoom_x = 20;
	all->fract.mouse_zoom_y = 20;
	all->fract.i_zoom = 1;
	all->fract.value_zoom = 200;
}

int	check_key(int keycode, t_all *all)
{
	if (keycode == UP || keycode == DOWN)
		move_hook(keycode, all);
	if (keycode == RIGHT || keycode == LEFT)
		move_hook(keycode, all);
	if (keycode == XK_Escape)
		closer(&all->vars);
	return (0);
}

int	closer(t_vars *vars)
{
	mlx_loop_end (vars->mlx);
	return (0);
}

void	create_win_img(t_vars *vars, t_data *img, int nb)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (free(vars->mlx));
	if (nb == 1)
		vars->win = mlx_new_window(vars->mlx, 400, 400, "Mandelbrot");
	else if (nb == 2)
		vars->win = mlx_new_window(vars->mlx, 400, 400, "Julia");
	else if (nb == 3)
		vars->win = mlx_new_window(vars->mlx, 400, 400, "Julia 2");
	else if (nb == 4)
		vars->win = mlx_new_window(vars->mlx, 400, 400, "Julia 3");
	if (!vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		return (free(vars->mlx));
	}
	img->img = mlx_new_image(vars->mlx, 400, 400);
	if (!img->img)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, img->img);
		return (free(vars->mlx));
	}
	img->addr = (int *)mlx_get_data_addr(img->img, \
	&img->bits_per_pixel, &img->line_length, &img->endian);
}

int	fractol(int nb)
{
	t_all	all;

	all.nb = nb;
	all.vars.mlx = NULL;
	all.vars.win = NULL;
	create_win_img(&all.vars, &all.img, nb);
	if (!all.vars.mlx || !all.vars.win || !all.img.img)
		return (0);
	mlx_hook(all.vars.win, 2, 1L << 0, check_key, &all);
	mlx_hook(all.vars.win, 2, 1L << 0, check_key, &all);
	mlx_hook(all.vars.win, 17, 1L << 0, closer, &all.vars);
	init_hook(&all);
	mlx_mouse_hook(all.vars.win, mouse_hook, &all);
	create_fractal(all.fract, &all.img, &all.vars, nb);
	mlx_destroy_window(all.vars.mlx, all.vars.win);
	mlx_destroy_image(all.vars.mlx, all.img.img);
	mlx_destroy_display(all.vars.mlx);
	free(all.vars.mlx);
	return (1);
}
