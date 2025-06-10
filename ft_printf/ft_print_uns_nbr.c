/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:11:51 by auferran          #+#    #+#             */
/*   Updated: 2022/11/24 18:25:59 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_uns_nbr(unsigned int n)
{
	unsigned long long int	nb;
	int						len;

	nb = n;
	len = 0;
	if (nb > 9)
		len += ft_print_uns_nbr(nb / 10);
	len += ft_print_char(nb % 10 + 48);
	return (len);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d\n", ft_print_uns_nbr(atoi(argv[1])));
	return (0);
}
*/
