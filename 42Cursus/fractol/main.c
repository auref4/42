/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:22:58 by auferran          #+#    #+#             */
/*   Updated: 2023/03/23 04:09:42 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	int	nb;

	if (argc == 2)
	{
		nb = check_arg(argv);
		if (nb == 0)
			return (error(0), 0);
		fractol(nb);
	}
	else
		error(1);
	return (0);
}
