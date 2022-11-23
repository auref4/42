/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:59:20 by auferran          #+#    #+#             */
/*   Updated: 2022/11/23 19:21:19 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char format*, ...)
{
	int	i;
	int	len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_check_pc_letter(format[i + 1]))
			len = len + ft_print_type(format, ...);
		else if (format[i] != '%')
			len = len + ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
