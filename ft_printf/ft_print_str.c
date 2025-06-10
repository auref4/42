/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:29:16 by auferran          #+#    #+#             */
/*   Updated: 2022/11/24 18:26:09 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i += write (1, "(null)", 6);
		return (i);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d\n", ft_print_str(argv[1]));
	return (0);
}
*/
