#include "minishell.h"

void	minishell(char **env)
{
	char		*prompt;
	s_env_pipex	*env_pipex;

	(void) env;
	init_struct(env_pipex)
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
		else if (prompt && check_prompt(prompt, env_pipex))
			printf("go pipex !\n");
	}
}
