/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 04:59:03 by auferran          #+#    #+#             */
/*   Updated: 2023/02/07 06:20:45 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	manip_sig2(void)
{
	return (2);
}

int	manip_sig1(void)
{
	return (1);
}

int	waiting_sig(void)
{
	int	sig;

	sig = -1;
	sig = signal(SIGUSR2, manip_sig1);
	return (sig);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_error(int nb)
{
	if (nb == 1)
		ft_putstr("your PID should be unsigned integer\n");
}
