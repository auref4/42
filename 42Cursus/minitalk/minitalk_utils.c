/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 04:12:53 by auferran          #+#    #+#             */
/*   Updated: 2023/02/07 06:47:18 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')	
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb);
}

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    ft_putnbr(unsigned long nb)
{
        if (nb > 9)
                ft_putnbr(nb / 10);
        ft_putchar(nb % 10 + 48);
}

int    voyager(long int pid, char c)
{
        int     i;
	int	killer;

        i = 7;
	killer = 0;
        while (i >= 0)
        {
		if (c >> i % 2 == 0)
			killer = kill(pid, SIGUSR1);
                else
			killer = kill(pid, SIGUSR2);
		i--;
        }
	printf("kill = %d\n", killer);
	return (killer);
}

void    send_message(long int pid, char *str)
{
        int     i;

        i = 0;
        if (pid == -1)
                return (ft_error(1));
        while (str[i] != '\0')
        {
                voyager(pid, str[i]);
                i++;
        }
        voyager(pid, str[i]);
}
