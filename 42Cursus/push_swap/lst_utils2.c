/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:12:42 by auferran          #+#    #+#             */
/*   Updated: 2023/03/07 04:13:16 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_clear(t_lst **lst)
{
	t_lst	*tmp;
	int	i;
	int size;

	i = 0;
	size = ft_lst_size(*lst);
	while (i < size)
	{
		tmp = (*lst)->next;
		free (*lst);
		*lst = tmp;
		i++;
	}
	*lst = NULL;
}
