/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:53:16 by auferran          #+#    #+#             */
/*   Updated: 2023/03/01 03:17:52 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_signal;

void	voyager(char byte, int pid_server)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((byte >> i) % 2 == 0)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		i--;
		while (4)
		{
			if (g_signal == 1)
			{
				g_signal = 0;
				break ;
			}
		}
	}
}

void	send_message(int pid_server, char *str)
{
	int	i;

	i = 0;
	if (pid_server >= 0)
	{
		while (str[i])
		{
			voyager(str[i], pid_server);
			i++;
		}
		voyager(str[i], pid_server);
	}
	else
		ft_error(2);
}

void	sig_handler(int nb)
{
	if (nb == SIGUSR1)
	g_signal = 1;
}

int	main(int argc, char **argv)
{
	signal(SIGUSR1, sig_handler);
	if (argc == 3)
		send_message(ft_atoi(argv[1]), argv[2]);
	else
		ft_error(1);
}
