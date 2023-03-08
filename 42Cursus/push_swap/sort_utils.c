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
