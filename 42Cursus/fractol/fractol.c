/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:36:46 by auferran          #+#    #+#             */
/*   Updated: 2023/03/23 03:26:46 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol(int nb)
{
	(void) nb;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = NULL;
	mlx_win = NULL;
	create_win_img(&mlx, &mlx_win, &img);
	manage_pixel(mlx, mlx_win, &img);
}
