/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:35:46 by auferran          #+#    #+#             */
/*   Updated: 2023/01/21 01:24:21 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**dest;

	dest = NULL;
	if (argc > 1)
	{
		if (!check_arg(argv))
		{
			ft_error();
			return (0);
		}
		dest = prep_arg(argv);
		if (!dest)
			return (0);
		push_swap(dest);
	}
	if (argc <= 1)
		ft_error();
	if (!argv)
		ft_error();
	return (0);
}
