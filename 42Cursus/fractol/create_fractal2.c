#include "fractol.h"

void	color_julia(t_fract fract, t_data *img)
{
	if (fract.i == fract.i_max)
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x6C00FF;
	else
		img->addr[(fract.y * fract.image_x) + fract.x] = 0x000000;
}

void	value_julia(t_fract *fract)
{
	(*fract).x1 = -1;
	(*fract).x2 = 1;
	(*fract).y1 = -1.2;
	(*fract).y2 = 1.2;
	(*fract).image_x = 800;
	(*fract).image_y = 800;
	(*fract).i_max = 70;
	(*fract).zoom_x = (*fract).image_x / ((*fract).x2 - (*fract).x1);
	(*fract).zoom_y = (*fract).image_y / ((*fract).y2 - (*fract).y1);
}

void	calcul_julia_3(t_fract fract, t_data *img, t_vars *vars)
{
	fract.y = 0;
	while (fract.y++ < fract.image_y)
	{
		fract.x = 0;
		while (fract.x++ < fract.image_x)
		{
			fract.c_r =  -0.4;
			fract.c_i =  0.6;
			fract.z_r = (fract.x / fract.zoom_x) + fract.x1;
			fract.z_i = (fract.y / fract.zoom_y) + fract.y1;
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
			color_julia(fract, img);
		}
	}
	mlx_put_image_to_window((*vars).mlx, (*vars).win, img->img, 0, 0);
	mlx_loop((*vars).mlx);
}

void	calcul_julia_2(t_fract fract, t_data *img, t_vars *vars)
{
	fract.y = 0;
	while (fract.y++ < fract.image_y)
	{
		fract.x = 0;
		while (fract.x++ < fract.image_x)
		{
			fract.c_r = 0.3;
			fract.c_i = 0.5;
			fract.z_r = (fract.x / fract.zoom_x) + fract.x1;
			fract.z_i = (fract.y / fract.zoom_y) + fract.y1;
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
			color_julia(fract, img);
		}
	}
	mlx_put_image_to_window((*vars).mlx, (*vars).win, img->img, 0, 0);
	mlx_loop((*vars).mlx);
}

void	calcul_julia(t_fract fract, t_data *img, t_vars *vars)
{
	fract.y = 0;
	while (fract.y++ < fract.image_y)
	{
		fract.x = 0;
		while (fract.x++ < fract.image_x)
		{
			fract.c_r = 0.285;
			fract.c_i = 0.01;
			fract.z_r = (fract.x / fract.zoom_x) + fract.x1;
			fract.z_i = (fract.y / fract.zoom_y) + fract.y1;
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
			color_julia(fract, img);
		}
	}
	mlx_put_image_to_window((*vars).mlx, (*vars).win, img->img, 0, 0);
	mlx_loop((*vars).mlx);
}
