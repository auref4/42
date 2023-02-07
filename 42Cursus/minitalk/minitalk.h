/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 04:01:46 by auferran          #+#    #+#             */
/*   Updated: 2023/02/07 06:18:34 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

typedef	struct s_list
{
	char	c;
	struct s_list *next;
}	t_list;
long int	ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(unsigned long nb);
int	voyager(long int pid, char c);
void	send_message(long int pid, char *str);
void	ft_error(int nb);
void	ft_putstr(char *str);

#endif
