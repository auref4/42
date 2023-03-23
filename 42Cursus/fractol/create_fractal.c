/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:35:29 by auferran          #+#    #+#             */
/*   Updated: 2023/03/23 01:58:59 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	manage_pixel(void *mlx, void *mlx_win, t_data *img)
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
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
}

void	create_win_img(void **mlx, void **mlx_win, t_data *img)
{
	*mlx = mlx_init();
	*mlx_win = mlx_new_window(*mlx, 1920, 1080, "foufurieux");
	img->img = mlx_new_image(*mlx, 1920, 1080);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
}
