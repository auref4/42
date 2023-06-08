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

int	closer(int keycode, t_vars *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	mandelbrot(t_fract fract, t_data *img, t_vars vars)
{
	fract.x1 = -2.1;
	fract.x2 = 0.6;
	fract.y1 = -1.2;
	fract.y2 = 1.2;
	fract.image_x = 270;
	fract.image_y = 240;
	fract.i_max = 50;
	fract.zoom_x = fract.image_x / (fract.x2 - fract.x1);
	fract.zoom_y = fract.image_y / (fract.y2 - fract.y1);
	fract.y = 0;
	while (fract.y < fract.image_y)
	{
		fract.x = 0;
		while (fract.x < fract.image_x)
		{
			fract.c_r = (fract.x / fract.zoom_x) + fract.x1;
			fract.c_i = (fract.y / fract.zoom_y) + fract.y1;
			fract.z_r = 0;
			fract.z_i = 0;
			fract.i = 0;
			while((fract.z_r * fract.z_r) + (fract.z_i * fract.z_i) < 4 && fract.i < fract.i_max)
			{
				fract.tmp = fract.z_r;
				fract.z_r = (fract.z_r * fract.z_r) - (fract.z_i * fract.z_i) + fract.c_r;
				fract.z_i = (2 * fract.tmp * fract.z_i) + fract.c_i;
				fract.i++;
			}
			if (fract.i == fract.i_max)
				img->addr[(fract.y * fract.image_x) + fract.x] = 0x27C1C4;
			fract.x++;
		}
		fract.y++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
	mlx_loop(vars.mlx);
}

void	manage_pixel(t_vars vars, t_data *img)
{
	int	i_long;
	int	i_larg;

	i_long = 0;
	while (i_long < 1000)
	{
		i_larg = 0;
		while (i_larg < 1500)
		{
			img->addr[i_long * 1500 + i_larg] = 0x27C1C4;
			i_larg++;
		}
		i_long++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
	mlx_loop(vars.mlx);
}

void	create_win_img(t_vars *vars, t_data *img, int nb)
{
	vars->mlx = mlx_init();
	if (nb == 1)
		vars->win = mlx_new_window(vars->mlx, 270, 240, "Mandelbrot");
	else if (nb == 2)
		vars->win = mlx_new_window(vars->mlx, 1500, 1000, "Julia");
	else
		return ;
	img->img = mlx_new_image(vars->mlx, 270, 240);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
}
