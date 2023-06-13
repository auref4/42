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
}

void	go_move(int keycode, t_all *all)
{
	if (keycode == UP || keycode == DOWN)
		up_and_down(keycode, all);
	if (keycode == RIGHT || keycode == LEFT)
		right_and_left(keycode, all);
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
