/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 04:10:05 by auferran          #+#    #+#             */
/*   Updated: 2023/02/07 06:40:25 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	int	i;
	unsigned long	pid;
	unsigned long	pid_client;
	char	*message;
	t_list	start;

	i = 0;
	pid = getpid();
	ft_putnbr(pid);
	while (4)
	{
		printf("sig = %d\n", waiting_sig());
		printf("i = %d\n", i);
		ft_putnbr(pid);
		i++;
		//ok_receive()
	}
}
