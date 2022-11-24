/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:10:57 by auferran          #+#    #+#             */
/*   Updated: 2022/11/24 18:26:19 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_hex(unsigned long int n, int c)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_print_hex(n / 16, c);
	if ((n % 16) < 10)
		len += ft_print_char((n % 16) + 48);
	else if (c == 'X')
		len += ft_print_char((n % 16) + 55);
	else if (c == 'x' || c == 'p')
		len += ft_print_char((n % 16) + 87);
	return (len);
}
