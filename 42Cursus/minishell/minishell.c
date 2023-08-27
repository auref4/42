#include "minishell.h"

int	manage_prompt(char *prompt)
{
	s_env_pipex	*env_pipex;

	env_pipex = NULL;
	if (particular_case(prompt))
		return (1);
	if (!init_struct(prompt, &env_pipex))
		return (error(ERROR_MALLOC), 0);
	if (!check_prompt(prompt, env_pipex))
		return (free(env_pipex), error(ERROR_PROMPT), 1);
	printf("go pipex !\n");
	free(env_pipex);
	return (1);
}

void	minishell(char **env)
{
	char		*prompt;

	(void) env;
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
		else if (prompt && !manage_prompt(prompt))
		{
			free(prompt);
			return ;
		}
		free(prompt);
	}
}
