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
		{
			pa(lst_a, lst_b);
			ft_putstr("pa\n");
		}
		else
		{
			rra(lst_a);
			ft_putstr("rra\n");
		}
	}
	while (is_sort(*lst_a) != 1)
	{
		rra(lst_a);
		ft_putstr("rra\n");
	}
}

void	my_algo(t_lst **lst_a, t_lst **lst_b, int first_a, int last_b)
{
	while (is_sort(*lst_a) != 1 || is_r_sort(*lst_b) != 1)
	{
		if (((*lst_b)->nb < (*lst_b)->next->nb) && ((*lst_a)->nb > (*lst_a)->next->nb))
			act_a_b(lst_a, lst_b, first_a, last_b);
		else if (((*lst_b)->nb > (*lst_b)->next->nb) && ((*lst_a)->nb < (*lst_a)->next->nb))
			no_act(lst_a, lst_b);
		else if (((*lst_b)->nb < (*lst_b)->next->nb) && ((*lst_a)->nb < (*lst_a)->next->nb))
			act_b(lst_a, lst_b, last_b);
		else if (((*lst_b)->nb > (*lst_b)->next->nb) && ((*lst_a)->nb > (*lst_a)->next->nb))
			act_a(lst_a, lst_b, first_a);
		if (verif_can_r_sort(lst_b))
			go_sort_b(lst_b);
		if (verif_can_sort(lst_a))
			go_sort_a(lst_a);
		//printf("first_a = %d\n", first_a);
		//printf("last_b = %d\n", last_b);
		//printf("lst_b->nb = %d\n", (*lst_b)->nb);
		//printf("lst_a->nb = %d\n", (*lst_a)->nb);
		//ft_putstr("lst_a =\n");
		//print_lst_TEMP(*lst_a);
		//ft_putstr("lst_b =\n");
		//print_lst_TEMP(*lst_b);
	}
}

void	sort(t_lst	**lst_a, t_lst **lst_b)
{
	int	first_nb;
	int	mid_nb;
	int	last_nb;

	if (is_sort(*lst_a) != 1)
	{
		if (ft_lst_size(*lst_a) == 2)
		{
			sa(lst_a);
			ft_putstr("sa\n");
		}
		else if (ft_lst_size(*lst_a) == 3)
			algo_for_3(lst_a);
		else if (ft_lst_size(*lst_a) == 5)
			algo_for_5(lst_a, lst_b);
		else
		{
			first_nb = get_first(*lst_a);
			mid_nb = get_middle(*lst_a);
			last_nb = get_last(*lst_a);
			push_mid(lst_a, lst_b, mid_nb);
			my_algo(lst_a, lst_b, first_nb, last_nb);
			insertion(lst_a, lst_b);
		}
	}
	//ft_putstr("lst_a =\n");
	//print_lst_TEMP(*lst_a);
	//ft_putstr("lst_b =\n");
	//print_lst_TEMP(*lst_b);
}
