#include "minishell"

char	*file_dup(char *prompt, char c, int *i)
{
	t_struct_file_dup d;

	ft_memset(&d, 0, sizeof(t_struct_file_dup));
	while (prompt[*i] == c)
	{
		d.count++;
		(*i)++;
	}
	if (d.count > 1)
		error("minishell: syntax error near unexpecter token\n");
	while (prompt[*i] && white_space(prompt[*i]))
		(*i)++;
	while (prompt[*i] && !white_space(prompt[*i]))
	{
		(*i)++;
		d.len++;
	}
	d.str = malloc(sizeof(char) * len + 1);
	if (!d.str)
		return (error("MALLOC FAILURE\n"));
	*i -= d.len;
	while (prompt[*i] && !white_space(prompt[*i]))
		str[d.j++] = prompt[(*i)++];
	str[d.j] = 0;
	return (d.str);
}

void	*fill_file(char *prompt, s_lst_file	**file, int *i)
{
	s_lst_file	*new;

	file = malloc(sizeof(t_lst_file));
	if (!file)
		return (error("ERROR MALLOC\n"));
	ft_memset(file, 0, sizeof(file));
	if (file(prompt[*i] == INFILE) && !file(prompt[*i + 1]))
		if (new->infile = file_dup(prompt, prompt[*i], i) == NULL)
			return ;
	else if (file(prompt[*i] == OUTFILE) && !file(prompt[*i + 1]))
		if (new->outfile = file_dup(prompt, prompt[*i], i) == NULL)
			return ;
	else if (file(prompt[*i] == INFILE) && file(prompt[*i + 1] == INFILE))
		if (new->limiter = file_dup(prompt, prompt[*i], i) == NULL)
			return ;
	else if (file(prompt[*i] == OUTFILE) && file(prompt[*i + 1] == OUTFILE))
	{
		new->outfile_type == 1;
		if (new->infile = file_dup(prompt, prompt[*i], i) == NULL)
			return ;
	}
	ft_lst_add_back_file(new, file);
}

void	fill_lst(char *prompt, t_lst_cmd **cmd)
{
	int			i;
	s_lst_file	*file;

	i = 0;
	file = NULL;
	while (prompt[i])
	{
		if (prompt[i] == '|')
			*cmd = *cmd->next;
		while (white_space(prompt[i]))
			i++;
		if (file(prompt[i]))
			fill_file(prompt, &file, *i);
	}
}
