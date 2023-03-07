/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:06:48 by auferran          #+#    #+#             */
/*   Updated: 2023/01/24 09:49:45 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(t_lst *lst_a)
{
	int	i;

	t_lst	*tmp;
	if (!lst_a)
		return (0);
	i = 1;
	tmp = lst_a;
	while (tmp->next)
	{
		if (tmp->next == lst_a)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_lst	*ft_lst_last(t_lst *lst_a)
{
	int	i;
	int	len;

	if (!lst_a)
		return (0);
	i = 0;
	len = ft_lst_size(lst_a);
	while (i < len -1)
	{
		lst_a = lst_a->next;
		i++;
	}
	return (lst_a);
}

t_lst	*ft_lst_new(int number, t_lst **lst_a)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->nb = number;
	new->next = *lst_a;
	return (new);
}

void	ft_add_front(t_lst **lst_a, t_lst *new)
{
	t_lst	*tmp;

	if (*lst_a == NULL)
	{
		*lst_a = new;
		(*lst_a)->next = new;
		(*lst_a)->prev = new;
		return ;
	}
	tmp = *lst_a;
	tmp->prev->next = new;
	new->next = tmp;
	new->prev = tmp->prev;
	tmp->prev = new;
	*lst_a = new;
}

void	ft_add_back(t_lst **lst_a, t_lst *new)
{
	t_lst	*tmp;

	tmp = NULL;
	if (*lst_a == NULL)
	{
		*lst_a = new;
		(*lst_a)->next = new;
		(*lst_a)->prev = new;
		return ;
	}
	tmp = (*lst_a)->prev;
	tmp->next = new;
	(*lst_a)->prev = new;
	new->prev = tmp;
	new->next = *lst_a;
}
