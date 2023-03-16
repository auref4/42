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
	t_lst	*tmp;

	i = 0;
	tmp = ft_lstmap(lst);
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
	(void) lst_a;
	(void) lst_b;
}
