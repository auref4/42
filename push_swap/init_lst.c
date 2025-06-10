/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 03:15:34 by auferran          #+#    #+#             */
/*   Updated: 2023/03/18 06:48:31 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char **dest)
{
	int	i;

	i = 0;
	if (!dest)
		return ;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free (dest);
}

int	init_lst(char **argv, t_lst **lst_a)
{
	int		i;
	int		j;
	int		nb;
	char	**tmp;
	t_lst	*new;

	i = 1;
	nb = 0;
	while (argv[i])
	{
		tmp = ft_split(argv[i++], ' ');
		j = 0;
		while (tmp && tmp[j])
		{
			nb = 0;
			if (!ft_atoi(tmp[j++], &nb))
				return (free_str(tmp), ft_lst_clear(lst_a), 0);
			new = ft_lst_new(nb, lst_a);
			if (!new)
				return (ft_lst_clear(lst_a), free_str(tmp), 0);
			ft_add_back(lst_a, new);
		}
		free_str(tmp);
	}
	return (1);
}
