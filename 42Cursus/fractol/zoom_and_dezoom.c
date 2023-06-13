#include "fractol.h"

void	calcul_mouse_zoom(t_all *all)
{
	all->fract.zoom_x = all->fract.zoom_x + all->fract.mouse_zoom_x;
	all->fract.zoom_y = all->fract.zoom_y + all->fract.mouse_zoom_y;
	all->fract.mouse_zoom_x = (all->fract.mouse_zoom_x) * 1.05;
	all->fract.mouse_zoom_y = (all->fract.mouse_zoom_y) * 1.05;
	if (all->fract.j == all->fract.j_max)
	{
		all->fract.j = 0;
		all->fract.i_max = all->fract.i_max + all->fract.i_zoom;
	}
	if (all->fract.zoom_x > all->fract.value_zoom)
	{
		all->fract.move = all->fract.move / 1.05;
		all->fract.value_zoom = all->fract.value_zoom + 100;
	}
	all->fract.j++;
}

void	go_zoom(t_all *all)
{
	if (all->nb == 1)
	{
		if(all->fract.check == 0)
			value_mandelbrot(&all->fract);
		calcul_mouse_zoom(all);
		calcul_mandelbrot(all->fract, &all->img, &all->vars);
	}
	if (all->nb == 2 || all->nb == 3 || all->nb == 4)
	{
		if(all->fract.check == 0)
			value_julia(&all->fract);
		calcul_mouse_zoom(all);
		if (all->nb == 2)
			calcul_julia(all->fract, &all->img, &all->vars);
		if (all->nb == 3)
			calcul_julia_2(all->fract, &all->img, &all->vars);
		if (all->nb == 4)
			calcul_julia_3(all->fract, &all->img, &all->vars);
	}
	all->fract.check++;
}

void	calcul_mouse_dezoom(t_all *all)
{
	all->fract.zoom_x = all->fract.zoom_x - all->fract.mouse_zoom_x;
	all->fract.zoom_y = all->fract.zoom_y - all->fract.mouse_zoom_y;
	all->fract.mouse_zoom_x = (all->fract.mouse_zoom_x) * 0.95;
	all->fract.mouse_zoom_y = (all->fract.mouse_zoom_y) * 0.95;
	if (all->fract.j == all->fract.j_max)
	{
		all->fract.j = 0;
		all->fract.i_max = all->fract.i_max - all->fract.i_zoom;
	}
	if (all->fract.zoom_x < all->fract.value_zoom)
	{
		all->fract.move = all->fract.move * 1.05;
		all->fract.value_zoom = all->fract.value_zoom - 100;
	}
	all->fract.j++;
}

void	go_dezoom(t_all *all)
{
	if (all->nb == 1)
	{
		if(all->fract.check == 0)
			value_mandelbrot(&all->fract);
		calcul_mouse_dezoom(all);
		calcul_mandelbrot(all->fract, &all->img, &all->vars);
	}
	if (all->nb == 2 || all->nb == 3 || all->nb == 4)
	{
		if(all->fract.check == 0)
			value_julia(&all->fract);
		calcul_mouse_dezoom(all);
		if (all->nb == 2)
			calcul_julia(all->fract, &all->img, &all->vars);
		if (all->nb == 3)
			calcul_julia_2(all->fract, &all->img, &all->vars);
		if (all->nb == 4)
			calcul_julia_3(all->fract, &all->img, &all->vars);
	}
	all->fract.check++;
}

int	mouse_hook(int keycode, int x, int y, t_all *all)
{
	(void) x;
	(void) y;
	if (keycode == ZOOM)
		go_zoom(all);
	if (keycode == DEZOOM)
		go_dezoom(all);
	return (0);
}
