#include "minishell.h"

void	free_all(char *prompt, s_env_pipex *env_pipex)
{
	free(prompt);
	free(env_pipex);
}
