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

void	my_algo(t_lst **lst_a, t_lst **lst_b)
{
	quick_sort(lst_a, lst_b);
	while (*lst_b)
	{
		if (its_sup(lst_b))
			pa(lst_a, lst_b);
		else if (search_sup(lst_b) > (ft_lst_size(*lst_b) / 2))
		{
			while (!its_sup(lst_b))
				rrb(lst_b);
		}
		else if (search_sup(lst_b) <= (ft_lst_size(*lst_b) / 2))
		{
			while (!its_sup(lst_b))
				rb(lst_b);
		}
	}
	//printf("first_a = %d\n", first_a);
	//printf("last_b = %d\n", last_b);
	//printf("lst_b->nb = %d\n", (*lst_b)->nb);
	//printf("lst_a->nb = %d\n", (*lst_a)->nb);
}

void	sort(t_lst	**lst_a, t_lst **lst_b)
{
	if (is_sort(*lst_a) != 1)
	{
		if (ft_lst_size(*lst_a) == 2)
			sa(lst_a);
		else if (ft_lst_size(*lst_a) == 3)
			algo_for_3(lst_a);
		else if (ft_lst_size(*lst_a) == 5)
			algo_for_5(lst_a, lst_b);
		else
			my_algo(lst_a, lst_b);
	}
	//ft_putstr("lst_a =\n");
	//print_lst_TEMP(*lst_a);
	//ft_putstr("lst_b =\n");
	//print_lst_TEMP(*lst_b);
}
