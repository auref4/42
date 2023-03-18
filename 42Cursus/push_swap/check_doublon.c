/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 01:35:33 by auferran          #+#    #+#             */
/*   Updated: 2023/03/18 00:05:29 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doublon_2(t_lst *tmp1, int size)
{
	int		i;
	int		j;
	t_lst	*tmp2;

	if (!tmp1)
		return (0);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		tmp2 = tmp1->next;
		while (j < size)
		{
			if (tmp1->nb == tmp2->nb)
				return (0);
			else
				tmp2 = tmp2->next;
			j++;
		}
		tmp1 = tmp1->next;
		i++;
	}
	return (1);
}

int	check_doublon(t_lst *lst_a)
{
	t_lst	*tmp1;
	int		size;
	int		ret;

	if (!lst_a)
		return (0);
	tmp1 = lst_a;
	if (!lst_a->next)
		return (1);
	size = ft_lst_size(lst_a);
	ret = check_doublon_2(tmp1, size);
	return (ret);
}
