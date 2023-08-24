#include "minishell.h"

int	check_nb_cmd(char *prompt)
{
	int	i;
	int	pipe;

	i = 0;
	pipe = 0;
	while (prompt[i])
	{
		if (prompt[i] == '|')
			pipe++;
		i++;
	}
	return (pipe);
}

int	init_struct(char *prompt, s_env_pipex *env_pipex)
{
	int	i;
	int	nb_cmd;

	i = 0;
	nb_cmd = check_nb_cmd(prompt) + 1;
	env_pipex = malloc(sizeof(s_env_pipex) * nb_cmd);
	if (!env_pipex)
		return (0);
	while (i < nb_cmd)
	{
		ft_memset(&env_pipex[i], 0, 5);
		i++;
	}
	/*printf("infile = %s\n", env_pipex->infile);
	printf("outfile = %s\n", env_pipex->outfile);
	printf("open_outfile_type = %d\n", env_pipex->open_outfile_type);
	printf("heredoc = %d\n", env_pipex->heredoc);
	printf("limiter = %s\n", env_pipex->limiter);
	printf("cmd = %s\n", env_pipex->cmd[0]);*/
	return (1);
}
