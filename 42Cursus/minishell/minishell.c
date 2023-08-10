#include "minishell.h"

void	minishell(char **env)
{
	char	*prompt;

	(void) env;
	manage_sig();
	while (1)
	{
		prompt = readline("minishell$ ");
		if (!prompt || !ft_strcmp("exit", prompt))
		{
			if (!ft_strcmp("exit", prompt))
				free(prompt);
			printf("exit\n");
			break ;
		}
		free(prompt);
	}
}
