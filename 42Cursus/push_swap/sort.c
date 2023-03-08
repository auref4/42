/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:36:49 by auferran          #+#    #+#             */
/*   Updated: 2023/03/07 06:46:46 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void push_mid_size(t_lst **lst_a, t_lst **lst_b)
{
	int	i;
	int	mid_size;

	if (!lst_a)
		return ;
	i = 0;
	mid_size = ft_lst_size(*lst_a) / 2;
	while (i < mid_size + 1)
	{
		pb(lst_a, lst_b);
		*lst_a = (*lst_a)->next;
		i++;
	}
	return ;
}

void	shaker_reverse(t_lst **lst)
{
	int	i;
	int	size;

	size = ft_lst_size(*lst);
	while (is_r_sort(*lst) != 1)
	{
		i = 0;
		while (i < size - 2)
		{
			if ((*lst)->nb < (*lst)->next->nb)
				sa(lst);
			ra(lst);
			i++;
		}
		i = 0;
		while (i < (size - 2))
		{
			if ((*lst)->nb < (*lst)->next->nb)
				sa(lst);
			rra(lst);
			i++;
		}
	}
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
				sa(lst);
			ra(lst);
			i++;
		}
		i = 0;
		while (i < (size - 2))
		{
			if ((*lst)->nb > (*lst)->next->nb)
				sa(lst);
			rra(lst);
			i++;
		}
	}
}

void	insertion(t_lst **lst_a, t_lst **lst_b)
{
	while (*lst_b)
	{
		if ((*lst_b)->nb > (*lst_a)->prev->nb)
			pa(lst_a, lst_b);
		else
			rra(lst_a);
	}
	while (is_sort(*lst_a) != 1)
		rra(lst_a);
}

void	sort(t_lst	**lst_a, t_lst **lst_b)
{
	push_mid_size(lst_a, lst_b);
	shaker_reverse(lst_b);
	shaker(lst_a);
	insertion(lst_a, lst_b);
}
