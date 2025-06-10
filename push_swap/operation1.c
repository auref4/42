/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:00:24 by auferran          #+#    #+#             */
/*   Updated: 2023/03/17 23:55:09 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_lst **lst_a)
{
	int	tmp;

	if (!(*lst_a) || ft_lst_size(*lst_a) <= 1)
		return ;
	tmp = (*lst_a)->nb;
	(*lst_a)->nb = (*lst_a)->next->nb;
	(*lst_a)->next->nb = tmp;
	ft_putstr("sa\n");
}

void	sb(t_lst **lst_b)
{
	int	tmp;

	if (!(*lst_b) || ft_lst_size(*lst_b) <= 1)
		return ;
	tmp = (*lst_b)->nb;
	(*lst_b)->nb = (*lst_b)->next->nb;
	(*lst_b)->next->nb = tmp;
	ft_putstr("sb\n");
}

void	ss(t_lst **lst_a, t_lst **lst_b)
{
	int	tmp;

	if (!(*lst_a) || ft_lst_size(*lst_a) <= 1)
		return ;
	if (!(*lst_b) || ft_lst_size(*lst_b) <= 1)
		return ;
	tmp = (*lst_a)->nb;
	(*lst_a)->nb = (*lst_a)->next->nb;
	(*lst_a)->next->nb = tmp;
	tmp = (*lst_b)->nb;
	(*lst_b)->nb = (*lst_b)->next->nb;
	(*lst_b)->next->nb = tmp;
	ft_putstr("ss\n");
}

void	pa(t_lst **lst_a, t_lst **lst_b)
{
	int		size;
	t_lst	*tmp_next;
	t_lst	*tmp_prev;

	if (!(*lst_b))
		return ;
	tmp_next = (*lst_b)->next;
	tmp_prev = (*lst_b)->prev;
	size = ft_lst_size(*lst_b);
	ft_add_front(lst_a, *lst_b);
	if (size == 1)
	{
		ft_putstr("pa\n");
		*lst_b = NULL;
		return ;
	}
	*lst_b = tmp_next;
	(*lst_b)->prev = tmp_prev;
	(*lst_b)->prev->next = *lst_b;
	(*lst_b)->next->prev = *lst_b;
	ft_putstr("pa\n");
}

void	pb(t_lst **lst_a, t_lst **lst_b)
{
	int		size;
	t_lst	*tmp_next;
	t_lst	*tmp_prev;

	if (!(*lst_a))
		return ;
	tmp_next = (*lst_a)->next;
	tmp_prev = (*lst_a)->prev;
	size = ft_lst_size(*lst_a);
	ft_add_front(lst_b, *lst_a);
	if (size == 1)
	{
		ft_putstr("pb\n");
		*lst_a = NULL;
		return ;
	}
	*lst_a = tmp_next;
	(*lst_a)->prev = tmp_prev;
	(*lst_a)->prev->next = *lst_a;
	(*lst_a)->next->prev = *lst_a;
	ft_putstr("pb\n");
}
