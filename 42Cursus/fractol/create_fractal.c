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
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	manage_pixel(t_vars vars, t_data *img)
{
	int	i_long;
	int	i_larg;

	i_long = 0;
	while (i_long < 1080)
	{
		i_larg = 0;
		while (i_larg < 1920)
		{
			img->addr[i_long * 1920 + i_larg] = 0x27C1C4;
			i_larg++;
		}
		i_long++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
	mlx_loop(vars.mlx);
}

void	create_win_img(t_vars *vars, t_data *img)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "foufurieux");
	img->img = mlx_new_image(vars->mlx, 1920, 1080);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
}
