#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void) argv;
	(void) env;
	if (argc == 1)
		minishell(env);
	else
		return (0);
}
