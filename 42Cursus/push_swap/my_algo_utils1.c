#include "push_swap.h"

void	act_a_b(t_lst **lst_a, t_lst **lst_b, int first_a, int last_b)
{
	int	last_a;
	int first_b;

	last_a = get_last(*lst_a);
	first_b = get_first(*lst_b);
	if ((*lst_b)->nb == first_b || (*lst_a)->nb == last_a)
	{
		if((*lst_b)->nb == first_b)
		{
			rb(lst_b);
			ft_putstr("rb\n");
		}
		if((*lst_a)->nb == last_a)
		{
			ra(lst_a);
			ft_putstr("ra\n");
		}
		return;
	}
	ss(lst_a, lst_b);
	ft_putstr("ss\n");
	while (((*lst_b)->nb >(*lst_b)->prev->nb) && ((*lst_a)->nb < (*lst_a)->prev->nb))
	{
		if ((*lst_b)->nb == last_b && (*lst_a)->nb == first_a)
			break;
		else if ((*lst_b)->nb == last_b && (*lst_a)->nb != first_a)
		{
			rra(lst_a);
			ft_putstr("rra\n");
			sa(lst_a);
			ft_putstr("sa\n");
			rb(lst_b);
			ft_putstr("rb\n");
		}
		else if ((*lst_b)->nb != last_b && (*lst_a)->nb == first_a)
		{
			rrb(lst_a);
			ft_putstr("rrb\n");
			sb(lst_b);
			ft_putstr("sb\n");
			ra(lst_b);
			ft_putstr("ra\n");
		}
		else
		{
			rrr(lst_a, lst_b);
			ft_putstr("ss\n");
			ss(lst_a, lst_b);
			ft_putstr("ss\n");
		}
	}
}

void	no_act(t_lst **lst_a, t_lst **lst_b)
{
	if (is_r_sort(*lst_b) == 1 && is_sort(*lst_a) != 1)
	{
		ra(lst_a);
		ft_putstr("ra\n");
	}
	else if (is_r_sort(*lst_b) != 1 && is_sort(*lst_a) == 1)
	{
		rb(lst_b);
		ft_putstr("rb\n");
	}
	else if (is_r_sort(*lst_b) != 1 && is_sort(*lst_a) != 1)
	{
		rr(lst_a, lst_b);
		ft_putstr("rr\n");
	}
}

void	act_b(t_lst **lst_a, t_lst **lst_b, int last_b)
{
	sb(lst_b);
	ft_putstr("sb\n");
	while ((*lst_b)->nb > (*lst_b)->prev->nb)
	{
		if ((*lst_b)->nb == last_b)
			break;
		rrb(lst_b);
		ft_putstr("rrb\n");
		sb(lst_b);
		ft_putstr("sb\n");
	}
	if (is_sort(*lst_a) != 1)
	{
		ra(lst_a);
		ft_putstr("ra\n");
	}
}

void	act_a(t_lst **lst_a, t_lst **lst_b, int first_a)
{
	sa(lst_a);
	ft_putstr("sa\n");
	while ((*lst_a)->nb < (*lst_a)->prev->nb)
	{
		if ((*lst_a)->nb == first_a)
			break;
		rra(lst_a);
		ft_putstr("rra\n");
		sa(lst_a);
		ft_putstr("ss\n");
	}
	if (is_r_sort(*lst_b) != 1)
	{
		rb(lst_b);
		ft_putstr("rb\n");
	}
}
