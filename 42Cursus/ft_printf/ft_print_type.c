/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:54:59 by auferran          #+#    #+#             */
/*   Updated: 2022/11/24 18:26:04 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_type(va_list args, char c)
{
	int				len;
	unsigned long	p;

	len = 0;
	if (c == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (c == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (c == 'p')
	{
		p = va_arg(args, unsigned long int);
		if (!p)
			return (len += ft_print_str("(nil)"));
		len += write(1, "0x", 2);
		len += ft_print_hex(p, c);
	}
	else if (c == 'd' || c == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_print_uns_nbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		len += ft_print_char(c);
	return (len);
}
