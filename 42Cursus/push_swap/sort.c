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

int	ft_mid_nb(t_lst *lst)
{
	int	mid_size;

	mid_size = ft_lst_size(lst) / 2;
	shaker(&lst);
	print_lst_TEMP(lst);
	return (mid_size);
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

void push_mid(t_lst **lst_a, t_lst **lst_b, int	mid_nb)
{
	int	i;
	int	mid_size;

	if (!lst_a)
		return ;
	i = 0;
	mid_size = ft_lst_size(*lst_a) / 2;
	while (i < mid_size)
	{
		if ((*lst_a)->nb >= mid_nb)
		{
			pb(lst_a, lst_b);
			ft_putstr("pb\n");
			i++;
		}
		ra(lst_a);
		ft_putstr("ra\n");
	}
	return ;
}

void	sort(t_lst	**lst_a, t_lst **lst_b)
{
	int	mid_nb;

	mid_nb = get_middle(*lst_a);
	push_mid(lst_a, lst_b, mid_nb);
	ft_putstr("lst_a =\n");
	print_lst_TEMP(*lst_a);
	ft_putstr("lst_b =\n");
	print_lst_TEMP(*lst_b);
	//shaker_reverse(lst_b);
	//shaker(lst_a);
	//insertion(lst_a, lst_b);
}
