#include "push_swap.h"
#include <stdio.h>

int	is_sort(t_lst *lst)
{
	int	tmp;

	tmp = lst->nb;
	while (lst)
	{
		if (lst->next->nb == tmp)
			return (1);
		if (lst->nb > lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	get_mid_midlle(t_lst *lst, int mid)
{
	int	i;
	int	nb_tmp;
	t_lst	*tmp;

	i = 0;
	tmp = ft_lstmap_mid(lst, mid);
	shaker(&tmp);
	while (i < ft_lst_size(tmp) / 2)
	{
		tmp = tmp->next;
		i++;
	}
	nb_tmp = tmp->nb;
	ft_lst_clear(&tmp);
	return (nb_tmp);
}

void	quick_sort(t_lst **lst_a, t_lst **lst_b)
{
	int	mid;
	int	mid_mid;

	if (*lst_a)
	{
		if (ft_lst_size(*lst_a) >= 5)
		{
			mid = get_middle(*lst_a);
			mid_mid = get_mid_midlle(*lst_a, mid);
		}
		else
			mid_mid = (*lst_a)->nb;
		if ((*lst_a)->nb == mid_mid)
			ra(lst_a);
		while (*lst_a)
		{
			printf("mid = %d\n", mid);
			printf("mid_mid = %d\n", mid_mid);
			ft_putstr("lst_a =\n");
			print_lst_TEMP(*lst_a);
			ft_putstr("lst_b =\n");
			print_lst_TEMP(*lst_b);
			if ((*lst_a)->nb == mid_mid)
			{
				pb(lst_a, lst_b);
				quick_sort(lst_a, lst_b);
			}
			else if ((*lst_a)->nb < mid_mid)
				pb(lst_a, lst_b);
			else if ((*lst_a)->nb > mid_mid)
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
