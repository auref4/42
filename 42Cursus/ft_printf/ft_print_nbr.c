/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:48:28 by auferran          #+#    #+#             */
/*   Updated: 2022/11/24 18:26:15 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_nbr(int n)
{
	long long int	nb;
	int				len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_print_char('-');
		nb = nb * -1;
	}
	if (nb > 9)
		len += ft_print_nbr(nb / 10);
	len += ft_print_char(nb % 10 + 48);
	return (len);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d\n", ft_print_nbr(atoi(argv[1])));
}
*/
