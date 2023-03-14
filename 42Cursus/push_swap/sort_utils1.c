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

int	is_r_sort(t_lst *lst)
{
	int	tmp;

	tmp = lst->nb;
	while (lst)
	{
		if (lst->next->nb == tmp)
			return (1);
		if (lst->nb < lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
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
		while (i < size - 2)
		{
			if ((*lst)->nb > (*lst)->next->nb)
				sa(lst);
			rra(lst);
			i++;
		}
	}
}

int	ft_mid_nb(t_lst *lst)
{
	int	mid_size;

	mid_size = ft_lst_size(lst) / 2;
	shaker(&lst);
	print_lst_TEMP(lst);
	return (mid_size);
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
		else
		{
			ra(lst_a);
			ft_putstr("ra\n");
		}
	}
	return ;
}
