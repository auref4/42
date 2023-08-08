#include "minishell.h"

void	sig_handler(int signal)
{
	if (signal == SIGINT)
		printf("\nminishell$ ");
}

int	manage_sig()
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	return (1);
}
