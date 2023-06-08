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

void	fractol(int nb)
{
	t_data	img;
	t_vars	vars;
	t_fract	fract;

	vars.mlx = NULL;
	vars.win = NULL;
	create_win_img(&vars, &img, nb);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_hook(vars.win, 17, 1L<<0, closer, &vars);
	mandelbrot(fract, &img, vars);
	//manage_pixel(vars, &img);
}
