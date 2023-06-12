#include "fractol.h"

void	calcul_mouse_hook(t_all *all)
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
	printf("x1 = %f\n", all->fract.x1);
	printf("x2 = %f\n", all->fract.x2);
	printf("y1 = %f\n", all->fract.y1);
	printf("y2 = %f\n", all->fract.y2);
	printf("zoom_x = %f\n", all->fract.zoom_x);
	printf("zoom_y = %f\n", all->fract.zoom_y);
	printf("mouse_zoom_x = %f\n", all->fract.mouse_zoom_x);
	printf("mouse_zoom_y = %f\n", all->fract.mouse_zoom_y);
	printf("value_zoom = %f\n", all->fract.value_zoom);
	printf("i_zoom = %d\n", all->fract.i_zoom);
	printf("i_max = %d\n", all->fract.i_max);
	printf("j = %d\n", all->fract.j);
	printf("move = %Lf\n", all->fract.move);
	printf("-----------------------------\n");
}

void	go_zoom(t_all *all)
{
	if (all->nb == 1)
	{
		if(all->fract.check == 0)
			value_mandelbrot(&all->fract);
		calcul_mouse_hook(all);
		calcul_mandelbrot(all->fract, &all->img, &all->vars);
	}
	if (all->nb == 2 || all->nb == 3 || all->nb == 4)
	{
		if(all->fract.check == 0)
			value_julia(&all->fract);
		calcul_mouse_hook(all);
		if (all->nb == 2)
			calcul_julia(all->fract, &all->img, &all->vars);
		if (all->nb == 3)
			calcul_julia_2(all->fract, &all->img, &all->vars);
		if (all->nb == 4)
			calcul_julia_3(all->fract, &all->img, &all->vars);
	}
	all->fract.check++;
}

void	go_dezoom(t_all *all)
{
	(void) all;
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
