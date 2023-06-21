/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:31:00 by auferran          #+#    #+#             */
/*   Updated: 2023/06/21 16:45:10 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_julia_3(t_fract fract, t_data *img)
{
	if (fract.i == fract.i_max)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0xB7BDC7;
	else if (fract.i % 3 == 0 && fract.i % 5 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0xFFFFFF;
	else if (fract.i % 5 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x9C9C9C;
	else if (fract.i % 7 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x818181;
	else
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x444444;
}

void	color_julia_2(t_fract fract, t_data *img)
{
	if (fract.i == fract.i_max)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0xFFFFFF;
	else if (fract.i % 3 == 0 && fract.i % 5 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0xFFFDE3;
	else if (fract.i % 5 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0xEEF2FF;
	else if (fract.i % 7 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0xE3BAFF;
	else
		img->addr[(fract.y * fract.image_x) + fract.x] = 0xFEDDFE;
}

void	color_julia(t_fract fract, t_data *img)
{
	if (fract.i == fract.i_max)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x7F00A8;
	else if (fract.i % 3 == 0 && fract.i % 5 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x730000;
	else if (fract.i % 5 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x000856;
	else if (fract.i % 7 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x7000B4;
	else
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x000000;
}

void	color_mandelbrot(t_fract fract, t_data *img)
{
	if (fract.i == fract.i_max)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x000000;
	else if (fract.i % 3 == 0 && fract.i % 5 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0xB9FFAB;
	else if (fract.i % 5 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x36FFBC;
	else if (fract.i % 7 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0xABFBFF;
	else if (fract.i % 11 == 0)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x444444;
	else
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x00CDCA;
}
