#include "fractol.h"

void	up_and_down(int keycode, t_all *all)
{
	if (keycode == UP)
	{
		all->fract.y1 = all->fract.y1 - all->fract.move;
		all->fract.y2 = all->fract.y2 - all->fract.move;
	}
	if (keycode == DOWN)
	{
		all->fract.y1 = all->fract.y1 + all->fract.move;
		all->fract.y2 = all->fract.y2 + all->fract.move;
	}
}

void	right_and_left(int keycode, t_all *all)
{
	if (keycode == RIGHT)
	{
		all->fract.x1 = all->fract.x1 + all->fract.move;
		all->fract.x2 = all->fract.x2 + all->fract.move;
	}
	if (keycode == LEFT)
	{
		all->fract.x1 = all->fract.x1 - all->fract.move;
		all->fract.x2 = all->fract.x2 - all->fract.move;
	}
	//if(all->fract.check > 0)
	//	all->fract.move = all->fract.move - (all->fract.mouse_zoom_x / 10000);
}

void	go_move(int keycode, t_all *all)
{
	if (keycode == UP || keycode == DOWN)
		up_and_down(keycode, all);
	if (keycode == RIGHT || keycode == LEFT)
		right_and_left(keycode, all);
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
	printf("i_zoom = %d\n", all->fract.i_zoom);
	printf("i_max = %d\n", all->fract.i_max);
	printf("j = %d\n", all->fract.j);
	printf("move = %Lf\n", all->fract.move);
	printf("-----------------------------\n");
}

int	move_hook(int keycode, t_all *all)
{
	if(all->fract.check > 0)
	{
		go_move(keycode, all);
		if (all->nb == 1)
			calcul_mandelbrot(all->fract, &all->img, &all->vars);
		if (all->nb == 2)
			calcul_julia(all->fract, &all->img, &all->vars);
		if (all->nb == 3)
			calcul_julia_2(all->fract, &all->img, &all->vars);
		if (all->nb == 4)
			calcul_julia_3(all->fract, &all->img, &all->vars);
	}
	return (0);
}
