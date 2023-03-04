/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:48:17 by auferran          #+#    #+#             */
/*   Updated: 2023/03/04 01:08:44 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char **argv)
{
	int	i;
	int	j;

	if (!argv)
		return (0);
	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if(!is_digit(argv[i][j]) && argv[i][j] != '-' && argv[i][j] != ' ')
				return (0);
			if (argv[i][j] == '-' && !is_digit(argv[i][j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return(1);
}
