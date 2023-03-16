/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:18:57 by auferran          #+#    #+#             */
/*   Updated: 2023/03/07 06:46:50 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ra(t_lst **lst_a)
{
	*lst_a = (*lst_a)->next;
	ft_putstr("ra\n");
}

void	rb(t_lst **lst_b)
{
	*lst_b = (*lst_b)->next;
	ft_putstr("rb\n");
}

void	rr(t_lst **lst_a, t_lst **lst_b)
{
	*lst_a = (*lst_a)->next;
	*lst_b = (*lst_b)->next;
	ft_putstr("rr\n");
}

void	rra(t_lst **lst_a)
{
	*lst_a = (*lst_a)->prev;
	ft_putstr("rra\n");
}

void	rrb(t_lst **lst_b)
{
	*lst_b = (*lst_b)->prev;
	ft_putstr("rrb\n");
}

