#include "push_swap.h"
#include <stdio.h>

void	quick_sort(t_lst **lst_a, t_lst **lst_b)
{
	int	mid;

	if (*lst_a)
	{
		if (ft_lst_size(*lst_a) >= 5)
			mid = get_middle(*lst_a);
		else
			mid = (*lst_a)->nb;
		if ((*lst_a)->nb == mid)
			ra(lst_a);
		while (4)
		{
			if (is_sort(*lst_a))
				return ;
			else if ((*lst_a)->nb == mid)
			{
				pb(lst_a, lst_b);
				quick_sort(lst_a, lst_b);
			}
			else if ((*lst_a)->nb < mid)
				pb(lst_a, lst_b);
			else if ((*lst_a)->nb > mid)
				ra(lst_a);
		}
	}
}

int	its_sup(t_lst **lst)
{
	t_lst *tmp;
	int	nb_tmp;

	tmp = ft_lstmap(*lst);
	nb_tmp = tmp->nb;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->nb == nb_tmp)
		{
			ft_lst_clear(&tmp);
			return (1);
		}
		if (tmp->nb > nb_tmp)
			break;
		tmp = tmp->next;
	}
	ft_lst_clear(&tmp);
	return (0);
}

int	search_sup(t_lst **lst)
{
	t_lst	*tmp;
	int	i;

	tmp = ft_lstmap(*lst);
	i = 0;
	while (tmp)
	{
		if (its_sup(&tmp))
			break ;
		tmp = tmp->next;
		i++;
	}
	ft_lst_clear(&tmp);
	return (i);
}

void	sort_and_push(t_lst **lst_a, t_lst **lst_b)
{
	while (*lst_b)
	{
		if (its_sup(lst_b))
			pa(lst_a, lst_b);
		else if (search_sup(lst_b) > (ft_lst_size(*lst_b) / 2))
		{
			while (!its_sup(lst_b))
				rrb(lst_b);
		}
		else if (search_sup(lst_b) <= (ft_lst_size(*lst_b) / 2))
		{
			while (!its_sup(lst_b))
				rb(lst_b);
		}
	}
}
