/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:49:54 by auferran          #+#    #+#             */
/*   Updated: 2023/01/24 09:49:49 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **argv)
{
	int	i;

	t_elmt *first_a;
//	t_elmt *elmt_b;
	t_elmt *new;
	i = 1;
	first_a = NULL;
	while (argv[i])
	{
		new = ft_elmt_new(ft_atoi(argv[i]), t_elmt *first_a);
		if (!new)
			return (ft_error()); // pas oublier lstclear
		ft_add_back(&first_a, new);
		i++;
	}
	return;
}
