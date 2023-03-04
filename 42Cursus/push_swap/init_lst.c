/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 03:15:34 by auferran          #+#    #+#             */
/*   Updated: 2023/03/04 03:28:01 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_lst(char **dest, t_lst **lst_a)
{
	int	i;
	int	nb;
	t_lst *new;

	i = 0;
	nb = 0;
	new = NULL;
	while (dest[i])
	{
		nb = 0;
		if (!ft_atoi(dest[i], &nb))
			return (ft_error());
		new = ft_lst_new(nb, lst_a);
		if (!new)
		{
			ft_lst_clear(lst_a);
			return (ft_error());
		}
		ft_add_back(lst_a, new);
		i++;
	}
}
