#include "minishell"

t_lst_cmd	*fill_file(char *prompt, int *i)
{
	s_lst_file	*file;

	file = malloc(sizeof(t_lst_file));
	ft_memset(file, 0, sizeof(file));
	if (!file)
		return (error("ERROR MALLOC\n"));
	if (file(prompt[*i] == INFILE) && !file(prompt[*i + 1]))
		if (file->infile = file_dup(prompt, *i) == NULL)
			return (NULL);
	else if (file(prompt[*i] == OUTFILE) && !file(prompt[*i + 1]))
		if (file->outfile = file_dup(prompt, *i) == NULL)
			return (NULL);
	else if (file(prompt[*i] == INFILE) && file(prompt[*i + 1] == INFILE))
		if (file->limiter = file_dup(prompt, *i) == NULL)
			return (NULL);
	else if (file(prompt[*i] == OUTFILE) && file(prompt[*i + 1] == OUTFILE))
		if (file->infile = file_dup(prompt, *i) == NULL)
			return (NULL);
	return (file);
}

void	fill_lst(char *prompt, t_lst_cmd **cmd)
{
	int			i;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == '|')
			*cmd = *cmd->next;
		while (white_space(prompt[i]))
			i++;
		if (file(prompt[i]))
			*cmd->file = fill_file(prompt, cmd, &file, *i);
	}
}
