#include "push_swap.h"


void	sa(t_lst **lst_a)
{
	int	tmp;

	if (!(*lst_a) || ft_lst_size(*lst_a) <= 1)
		return;
	tmp = (*lst_a)->nb;
	(*lst_a)->nb = (*lst_a)->next->nb;
	(*lst_a)->next->nb = tmp;
}

void	sb(t_lst **lst_b)
{
	int	tmp;

	if (!(*lst_b) || ft_lst_size(*lst_b) <= 1)
		return;
	tmp = (*lst_b)->nb;
	(*lst_b)->nb = (*lst_b)->next->nb;
	(*lst_b)->next->nb = tmp;
}

void	ss(t_lst **lst_a, t_lst **lst_b)
{
	sa(lst_a);
	sb(lst_b);
}
