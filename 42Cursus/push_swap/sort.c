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

void	my_algo(t_lst **lst_a, t_lst **lst_b, int first_nb, int last_nb)
{
	while (is_sort(*lst_a) != 1 && is_r_sort(*lst_b) != 1)
	{
		if (((*lst_b)->nb < (*lst_b)->next->nb) && ((*lst_a)->nb > (*lst_a)->next->nb))
		{
			ss(lst_a, lst_b);
			ft_putstr("ss\n");
			while (((*lst_b)->nb >(*lst_b)->prev->nb) && ((*lst_a)->nb < (*lst_a)->prev->nb))
			{
				if ((*lst_b)->nb == first_nb && (*lst_a)->nb == last_nb)
					break;
				rrr(lst_a, lst_b);
				ft_putstr("ss\n");
				ss(lst_a, lst_b);
				ft_putstr("ss\n");
			}
		}
		else if (((*lst_b)->nb > (*lst_b)->next->nb) && ((*lst_a)->nb < (*lst_a)->next->nb))
		{
			if (is_r_sort(*lst_b) == 1 && is_sort(*lst_a) != 1)
			{
				ra(lst_a);
				ft_putstr("ra\n");
			}
			else if (is_r_sort(*lst_b) != 1 && is_sort(*lst_a) == 1)
			{
				rb(lst_b);
				ft_putstr("rb\n");
			}
			else
			{
				rr(lst_a, lst_b);
				ft_putstr("rr\n");
			}
		}
		else if (((*lst_b)->nb < (*lst_b)->next->nb) && (*lst_b)->next->nb != last_nb && ((*lst_a)->nb < (*lst_a)->next->nb))
		{
			sb(lst_b);
			ft_putstr("sb\n");
			while ((*lst_b)->nb > (*lst_b)->prev->nb)
			{
				if ((*lst_b)->nb == last_nb)
					break;
				rrb(lst_b);
				ft_putstr("rrb\n");
				sb(lst_b);
				ft_putstr("sb\n");
			}
			if (is_sort(*lst_a) != 1)
			{
				ra(lst_a);
				ft_putstr("ra\n");
			}
		}
		else if (((*lst_b)->nb < (*lst_b)->next->nb) && (*lst_b)->next->nb == last_nb && ((*lst_a)->nb < (*lst_a)->next->nb)) // POTENTIELLEMENT A SUPPRIMER
		{
			rb(lst_b);
			ft_putstr("rb\n");
			if (is_sort(*lst_a) != 1)
			{
				ra(lst_a);
				ft_putstr("ra\n");
			}
		}
		else if (((*lst_b)->nb > (*lst_b)->next->nb) && ((*lst_a)->nb > (*lst_a)->next->nb))
		{
			sa(lst_a);
			ft_putstr("sa\n");
			while ((*lst_a)->nb < (*lst_a)->prev->nb)
			{
				if ((*lst_a)->nb == first_nb)
					break;
				rra(lst_a);
				ft_putstr("rra\n");
				sa(lst_a);
				ft_putstr("ss\n");
			}
			if (is_r_sort(*lst_b) != 1)
			{
				rb(lst_b);
				ft_putstr("rb\n");
			}
		}
		ft_putstr("lst_a =\n");
		print_lst_TEMP(*lst_a);
		ft_putstr("lst_b =\n");
		print_lst_TEMP(*lst_b);
	}
}

void	sort(t_lst	**lst_a, t_lst **lst_b)
{
	int	first_nb;
	int	mid_nb;
	int	last_nb;

	first_nb = get_first(*lst_a);
	mid_nb = get_middle(*lst_a);
	last_nb = get_last(*lst_a);
	push_mid(lst_a, lst_b, mid_nb);
	my_algo(lst_a, lst_b, first_nb, last_nb);
	//insertion(lst_a, lst_b);
	//ft_putstr("lst_a =\n");
	//print_lst_TEMP(*lst_a);
	//ft_putstr("lst_b =\n");
	//print_lst_TEMP(*lst_b);
}
