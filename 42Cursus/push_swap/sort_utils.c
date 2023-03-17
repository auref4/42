/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 05:49:52 by auferran          #+#    #+#             */
/*   Updated: 2023/03/07 06:46:49 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_shaker(t_lst **lst)
{
	int	tmp;

	tmp = (*lst)->nb;
	(*lst)->nb = (*lst)->next->nb;
	(*lst)->next->nb = tmp;
}

void	shaker(t_lst **lst)
{
	int	i;
	int	size;

	size = ft_lst_size(*lst);
	while (is_sort(*lst) != 1)
	{
		i = 0;
		while (i < size - 2)
		{
			if ((*lst)->nb > (*lst)->next->nb)
				swap_shaker(lst);
			*lst = (*lst)->next;
			i++;
		}
		i = 0;
		while (i < size - 2)
		{
			if ((*lst)->nb > (*lst)->next->nb)
				swap_shaker(lst);
			*lst = (*lst)->prev;
			i++;
		}
	}
}

int	get_middle(t_lst *lst)
{
	int	i;
	int	nb_tmp;
	int	div;
	t_lst	*tmp;

	i = 0;
	tmp = ft_lstmap(lst);
	shaker(&tmp);
	if (ft_lst_size(tmp) <= 5)
		div = ft_lst_size(tmp) / 2;
	else if (ft_lst_size(tmp) > 5 && ft_lst_size(tmp) <= 100)
		div = ft_lst_size(tmp) / 4;
	else if (ft_lst_size(tmp) > 100)
		div = ft_lst_size(tmp) / 8;
	while (i < div)
	{
		tmp = tmp->next;
		i++;
	}
	nb_tmp = tmp->nb;
	ft_lst_clear(&tmp);
	return (nb_tmp);
}

void	algo_for_3(t_lst **lst)
{
	while (is_sort(*lst) != 1)
	{
		if ((*lst)->nb > (*lst)->next->nb)
			sa(lst);
		else if (is_sort(*lst) != 1)
			rra(lst);
	}
}

void	algo_for_5(t_lst **lst_a, t_lst **lst_b)
{
	int	i;
	int	mid;

	i = 0;
	mid = get_middle(*lst_a);
	while (i < (ft_lst_size(*lst_a) / 2))
	{
		if ((*lst_a)->nb < mid)
		{
			pb(lst_a, lst_b);
			i++;
		}
		else
			ra(lst_a);

	}
	algo_for_3(lst_a);
	if ((*lst_b)->nb < (*lst_b)->next->nb)
		sb(lst_b);
	pa(lst_a, lst_b);
	pa(lst_a, lst_b);
}
