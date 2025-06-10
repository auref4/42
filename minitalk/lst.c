/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:00:16 by auferran          #+#    #+#             */
/*   Updated: 2023/03/01 04:36:56 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_lst_size(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

char	*ft_lst_join(t_lst *lst)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * ft_lst_size(lst));
	if (!str)
		return (NULL);
	while (lst)
	{
		str[i] = lst->character;
		i++;
		lst = lst->next;
	}
	return (str);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

t_lst	*ft_elmt_new(char c)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->character = c;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}
