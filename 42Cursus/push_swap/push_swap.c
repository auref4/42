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

void	push_swap(char **dest)
{
	int	i;
	int	nb;

	t_lst *lst_a;
	t_lst *new;
	lst_a = NULL;
	new = NULL;
	i = 0;
	while (dest[i])
	{
		nb = 0;
		if (!ft_atoi(dest[i], &nb))
			return;
		new = ft_lst_new(nb, lst_a);
		if (!new)
			return (ft_error()); // pas oublier lstclear
		ft_add_back(&lst_a, new);
		i++;
	}
	/*t_lst	*tmp;
	tmp = lst_a;
	while (tmp->next)
	{
		printf("number = %d\n", tmp->nb);
		if (tmp->next == lst_a)
			return ;
		tmp = tmp->next;
	}*/
	free_dest(dest);
}
