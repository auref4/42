/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:59:20 by auferran          #+#    #+#             */
/*   Updated: 2022/11/25 12:56:58 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_check_pc_letter(format[i + 1]))
		{
			len += ft_print_type(args, format[i + 1]);
			i++;
		}
		else
			len += ft_print_char(format[i]);
		if (len == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (len);
}
