/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:56:21 by auferran          #+#    #+#             */
/*   Updated: 2022/11/24 18:25:46 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_check_pc_letter(char c);
int	ft_print_char(char c);
int	ft_print_type(va_list args, char c);
int	ft_print_str(char *str);
int	ft_print_nbr(int n);
int	ft_print_uns_nbr(unsigned int n);
int	ft_print_hex(unsigned long int n, int c);

#endif
