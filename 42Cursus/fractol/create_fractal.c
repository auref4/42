/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:35:29 by auferran          #+#    #+#             */
/*   Updated: 2023/03/23 05:31:48 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_mandelbrot(t_fract fract, t_data *img)
{
	if (fract.i == fract.i_max)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x000000;
	else if (fract.i % 3 == 0 && fract.i % 5 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x00BAC6;
	else if (fract.i % 3 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x00F0FF;
	else if (fract.i % 5 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x00DDEC;
	else
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x00F0FF;
}


void	value_mandelbrot(t_fract *fract)
{
	fract->x1 = -2.1;
	fract->x2 = 0.6;
	fract->y1 = -1.2;
	fract->y2 = 1.2;
	fract->image_x = 400;
	fract->image_y = 400;
	fract->i_max = 50;
	fract->zoom_x = fract->image_x / (fract->x2 - fract->x1);
	fract->zoom_y = fract->image_y / (fract->y2 - fract->y1);
}

void	calcul_mandelbrot(t_fract fract, t_data *img, t_vars *vars)
{
	fract.y = 0;
	while (fract.y++ < fract.image_y)
	{
		fract.x = 0;
		while (fract.x++ < fract.image_x)
		{
			fract.c_r = (fract.x / fract.zoom_x) + fract.x1;
			fract.c_i = (fract.y / fract.zoom_y) + fract.y1;
			fract.z_r = 0;
			fract.z_i = 0;
			fract.i = 0;
			while((fract.z_r * fract.z_r) + (fract.z_i * fract.z_i)
				< 4 && fract.i < fract.i_max)
			{
				fract.tmp = fract.z_r;
				fract.z_r = (fract.z_r * fract.z_r)
					- (fract.z_i * fract.z_i) + fract.c_r;
				fract.z_i = (2 * fract.tmp * fract.z_i) + fract.c_i;
				fract.i++;
			}
			color_mandelbrot(fract, img);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
}

void	create_fractal(t_fract fract, t_data *img, t_vars *vars, int nb)
{
	if (nb == 1)
	{
		value_mandelbrot(&fract);
		calcul_mandelbrot(fract, img, vars);
	}
	if (nb == 2 || nb == 3 || nb == 4)
	{
		value_julia(&fract);
		if(nb == 2)
			calcul_julia(fract, img, vars);
		if (nb == 3)
			calcul_julia_2(fract, img, vars);
		if (nb == 4)
			calcul_julia_3(fract, img, vars);
	}
	mlx_loop(vars->mlx);
}
