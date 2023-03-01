/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:52:50 by auferran          #+#    #+#             */
/*   Updated: 2023/03/01 03:39:09 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	def_gest(t_sigaction sigact)
{
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	sigaction(SIGINT, &sigact, NULL);
}

void	get_char(int sig, char *bi)
{
	if (sig == SIGUSR1)
		*bi = *bi * 2;
	if (sig == SIGUSR2)
		*bi = *bi * 2 + 1;
}

void	sig_receipt(int sig, siginfo_t *info, void *v)
{
	static t_lst	*lst;
	static int		count;
	static char		bi;
	char			*str;

	(void) v;
	str = NULL;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		get_char(sig, &bi);
		count++;
		if (count == 8)
		{
			ft_lstadd_back(&lst, ft_elmt_new(bi));
			if (bi == '\0')
				join_and_write(&lst, &str);
			count = 0;
			bi = 0;
		}
		kill(info->si_pid, SIGUSR1);
	}
}

void	def_sigact(t_sigaction *sigact)
{
	ft_memset(sigact, 0, sizeof(t_sigaction));
	sigact->sa_sigaction = &sig_receipt;
	sigact->sa_flags = SA_SIGINFO;
}

int	main(void)
{
	t_sigaction	sigact;

	ft_putnbr(getpid());
	ft_putchar('\n');
	def_sigact(&sigact);
	def_gest(sigact);
	while (4)
		;
}
