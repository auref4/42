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

void	checker_a_b(t_lst **lst_a, t_lst **lst_b)
{
	int	i;
	int	size;
	(void) lst_b;

	size = ft_lst_size(*lst_a);
	//printf("pile A avant boucle\n");
	//print_lst_TEMP(*lst_a);
	while (lst_a)
	{
		printf("pile A pendant boucle\n");
		print_lst_TEMP(*lst_a);
		i = 0;
		while (i < (size - 2))
		{
			if ((*lst_a)->nb < (*lst_a)->next->nb)
			{
				sa(lst_a);
				ft_putstr("sa\n");
			}
			//printf("pile A pendant boucle\n");
			//print_lst_TEMP(*lst_a);
			rra(lst_a);
			//ft_putstr("ra\n");
			i++;
		}
		printf("verif\n");
		printf("pile A pendant boucle\n");
		print_lst_TEMP(*lst_a);
		i = 0;
		while (i < size - 2)
		{
			if ((*lst_a)->nb < (*lst_a)->next->nb)
			{
				sa(lst_a);
				ft_putstr("sa\n");
			}
			//printf("pile A pendant boucle\n");
			//print_lst_TEMP(*lst_a);
			ra(lst_a);
			ft_putstr("ra\n");
			i++;
		}
		if (is_r_sort(*lst_a) == 1)
			return ;
	}
}

void	checker(t_lst **lst_a, t_lst **lst_b)
{
	push_mid_size(lst_a, lst_b);
	checker_a_b(lst_a, lst_b);
}

void	sort(t_lst	**lst_a, t_lst **lst_b)
{
	checker(lst_a, lst_b);
}
