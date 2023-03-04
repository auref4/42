/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst_TEMP.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 03:05:25 by auferran          #+#    #+#             */
/*   Updated: 2023/03/04 03:08:09 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_lst_TEMP(t_lst *lst_a)
{
	t_lst	*tmp;
	tmp = lst_a;
	while (tmp)
	{
		printf("number = %d\n", tmp->nb);
		if (tmp->next == lst_a)
			return ;
		tmp = tmp->next;
	}
}
