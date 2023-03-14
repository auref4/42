#include "push_swap.h"

int	verif_can_sort(t_lst **lst)
{
	t_lst *tmp;
	int	nb_tmp;

	tmp = ft_lstmap(*lst);
	nb_tmp = tmp->nb;
	while (tmp)
	{
		if (is_sort(tmp) == 1)
		{
			ft_lst_clear(&tmp);
			return (1);
		}
		if (tmp->next->nb == nb_tmp)
		{
			tmp = tmp->next;
			break;
		}
		tmp = tmp->next;

	}
	ft_lst_clear(&tmp);
	return (0);
}

int	verif_can_r_sort(t_lst **lst)
{
	t_lst *tmp;
	int	nb_tmp;

	tmp = ft_lstmap(*lst);
	nb_tmp = tmp->nb;
	while (tmp)
	{
		if (is_r_sort(tmp) == 1)
		{
			ft_lst_clear(&tmp);
			return (1);
		}
		if (tmp->next->nb == nb_tmp)
			break;
		tmp = tmp->next;
	}
	ft_lst_clear(&tmp);
	return (0);
}

void	go_sort_b(t_lst **lst_b)
{
	while (*lst_b)
	{
		if (is_r_sort(*lst_b))
			return;
		rb(lst_b);
		ft_putstr("rb\n");
	}
}

void	go_sort_a(t_lst **lst_a)
{
	while (*lst_a)
	{
		if (is_sort(*lst_a))
			return;
		ra(lst_a);
		ft_putstr("ra\n");
	}
}
