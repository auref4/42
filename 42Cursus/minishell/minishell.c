#include "minishell.h"

int	manage_prompt(char *prompt, s_env_pipex *env_pipex)
{
	if (!init_struct(prompt, env_pipex))
		return (free(prompt), error(ERROR_MALLOC), 0);
	if (!check_prompt(prompt, env_pipex))
		return (error(ERROR_PROMPT), 1);
	printf("go pipex !\n");
	return (1);
}

void	minishell(char **env)
{
	char		*prompt;
	s_env_pipex	*env_pipex;

	(void) env;
	env_pipex = NULL;
	manage_sig();
	while (1)
	{
		prompt = readline("(auferran&malancar)-[~/minishell]$ ");
		if (!prompt || !ft_strcmp("exit", prompt))
		{
			if (!ft_strcmp("exit", prompt))
				free(prompt);
			printf("exit\n");
			return ;
		}
		else
		{
			if (!manage_prompt(prompt, env_pipex))
				return ;
		}
		free_all(prompt, env_pipex);
	}
}
