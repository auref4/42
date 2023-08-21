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

void	init_struct(s_env_pipex *env_pipex, int nb_cmd)
{
	int	i;

	i = 0;
	while (i < nb_cmd)
	{
		ft_memset(&env_pipex[i], nb_cmd, 5);
		i++;
	}
}

int	check_prompt(char *prompt, s_env_pipex *env_pipex)
{
	int	nb_cmd;

	nb_cmd = check_nb_cmd(prompt) + 1;
	env_pipex = malloc(sizeof(s_env_pipex) * nb_cmd);
	if (!env_pipex)
		return (ERROR_MALLOC);
	init_struct(env_pipex, nb_cmd);
}
