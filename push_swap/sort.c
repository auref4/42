/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:36:49 by auferran          #+#    #+#             */
/*   Updated: 2023/03/18 05:48:58 by auferran         ###   ########.fr       */
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

void	my_algo(t_lst **lst_a, t_lst **lst_b)
{
	if (!(*lst_a))
		return ;
	quick_sort(lst_a, lst_b);
	sort_and_push(lst_a, lst_b);
}

void	sort(t_lst	**lst_a, t_lst **lst_b)
{
	int	size;

	if (!(*lst_a))
		return ;
	size = ft_lst_size(*lst_a);
	if (is_sort(*lst_a) != 1)
	{
		if (size == 2)
			sa(lst_a);
		else if (size == 3)
			algo_for_3(lst_a);
		else if (size == 5)
			algo_for_5(lst_a, lst_b);
		else
			my_algo(lst_a, lst_b);
	}
}
