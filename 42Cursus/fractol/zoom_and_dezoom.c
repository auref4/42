#include "fractol.h"

void	init_mouse_hook(t_all all)
{
	(void) all;
	all.fract.i_zoom = 1;
	all.fract.mouse_zoom_x = 1;
	all.fract.mouse_dezoom_x = 1;
	all.fract.mouse_zoom_y = 1;
	all.fract.mouse_dezoom_y = 1;
	all.fract.move_x1 = 0;
	all.fract.move_x1_n = 0;
	all.fract.move_x2 = 0;
	all.fract.move_x2_n = 0;
	all.fract.move_y1 = 0;
	all.fract.move_y1_n = 0;
	all.fract.move_y2 = 0;
	all.fract.move_y2_n = -0;
}

void	calcul_mouse_hook(t_all *all)
{
	all->fract.zoom_x = all->fract.zoom_x + all->fract.mouse_zoom_x;
	all->fract.zoom_y = all->fract.zoom_y + all->fract.mouse_zoom_y;
	all->fract.mouse_zoom_x = all->fract.mouse_zoom_x + 12;
	all->fract.mouse_zoom_y = all->fract.mouse_zoom_y + 12;
	all->fract.x2 = all->fract.x2 + all->fract.move_x2;
	all->fract.y2 = all->fract.y2 - all->fract.move_y2;
	all->fract.move_x2 = all->fract.move_x2 + 0.008;
	all->fract.move_y2 = all->fract.move_y2 - 0.008;
	all->fract.x1 = all->fract.x1 + all->fract.move_x1;
	all->fract.y1 = all->fract.y1 - all->fract.move_y1;
	all->fract.move_x1 = all->fract.move_x1 + 0.008;
	all->fract.move_y1 = all->fract.move_y1 - 0.008;
	all->fract.i_zoom++;
}

void	go_zoom(t_all *all)
{
	if (all->nb == 1)
	{
		value_mandelbrot(&all->fract);
		calcul_mouse_hook(all);
		calcul_mandelbrot(all->fract, &all->img, &all->vars);
	}
	if (all->nb == 2 || all->nb == 3 || all->nb == 4)
	{
		value_julia(&all->fract);
		calcul_mouse_hook(all);
		if (all->nb == 2)
			calcul_julia(all->fract, &all->img, &all->vars);
		if (all->nb == 3)
			calcul_julia_2(all->fract, &all->img, &all->vars);
		if (all->nb == 4)
			calcul_julia_3(all->fract, &all->img, &all->vars);
	}
}

void	go_dezoom(t_all *all)
{
	(void) all;
}

int	mouse_hook(int keycode, int x, int y, t_all *all)
{
	(void) x;
	(void) y;
	if (keycode == 4)
		go_zoom(all);
	if (keycode == 5)
		go_dezoom(all);
	return (0);
}
