/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:49:54 by auferran          #+#    #+#             */
/*   Updated: 2023/03/04 03:30:21 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_swap(char **argv)
{
	t_lst	*lst_a;
	//t_lst	*lst_b;

	lst_a = NULL;
	//lst_b = NULL;
	init_lst(argv, &lst_a);
	if (!check_doublon(lst_a))
		return(ft_error());
	printf("pile avant op\n");
	print_lst_TEMP(lst_a);
	sa(&lst_a);
	printf("pile apres op\n");
	print_lst_TEMP(lst_a);
	ft_lst_clear(&lst_a);
}
