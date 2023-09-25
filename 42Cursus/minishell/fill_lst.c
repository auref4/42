#include "minishell"

char	*dup_file(char *prompt, char c, int *i)
{
	t_struct_dup_file	s;

	ft_memset(&s, 0, sizeof(t_struct_file_dup));
	while (prompt[*i] && prompt[*i] == c)
	{
		s.count++;
		(*i)++;
	}
	if (s.count > 1)
		error("minishell: syntax error near unexpecter token\n");
	while (prompt[*i] && white_space(prompt[*i]))
		(*i)++;
	while (prompt[*i] && !white_space(prompt[*i]))
	{
		(*i)++;
		s.len++;
	}
	s.str = malloc(sizeof(char) * len + 1);
	if (!s.str)
		return (error("MALLOC FAILURE\n"));
	*i -= s.len;
	while (prompt[*i] && !white_space(prompt[*i]))
		str[s.j++] = prompt[(*i)++];
	str[s.j] = 0;
	return (s.str);
}

void	*fill_file(char *prompt, s_lst_file	**file, int *i)
{
	t_lst_file	*new;

	new = malloc(sizeof(t_lst_file));
	if (!new)
		return (error("ERROR MALLOC\n"));
	ft_memset(new, 0, sizeof(t_lst_file));
	if (file(prompt[*i] == INFILE) && !file(prompt[*i + 1]))
		if (new->infile = dup_file(prompt, prompt[*i], i) == NULL)
			return ;
	else if (file(prompt[*i] == OUTFILE) && !file(prompt[*i + 1]))
		if (new->outfile = dup_file(prompt, prompt[*i], i) == NULL)
			return ;
	else if (file(prompt[*i] == INFILE) && file(prompt[*i + 1] == INFILE))
		if (new->limiter = dup_file(prompt, prompt[*i], i) == NULL)
			return ;
	else if (file(prompt[*i] == OUTFILE) && file(prompt[*i + 1] == OUTFILE))
	{
		new->outfile_type == 1;
		if (new->infile = dup_file(prompt, prompt[*i], i) == NULL)
			return ;
	}
	ft_lst_add_back_file(new, file);
}

char	*dup_arg(char *prompt, int *i)
{
	t_struct_dup_arg	s;

	while (prompt[*i] && white_space(prompt[i]))
		(i++);
	s.len = 0;
	while (prompt[*i] && prompt[*i] != '|' && !white_space(prompt[*i]))
	{
		s.len++;
		(*i)++;
	}
	s.str = malloc(sizeof(char) * s.len + 1);
	if (!s.str)
		return (error("MALLOC FAILURE\n"));
	s.j = 0;
	*i -= len;
	while (prompt[*i] && prompt[*i] != '|' && !white_space(prompt[*i]))
		s.str[s.j++] = prompt[(*i)++];
	s.str[s.j] = 0;
	return (s.str);
}

void	fill_arg(char *prompt, t_lst_arg **arg, int *i)
{
	int			j;
	int			len;
	t_lst_arg	*new;

	new = malloc(sizeof(t_lst_arg));
	if (!new)
		return (error("ERROR MALLOC\n"));
	ft_memset(new, 0, sizeof(t_lst_arg));
	if (new->name = dup_arg(prompt, i) == NULL)
		return ;
}

void	fill_lst(char *prompt, t_lst_cmd **cmd)
{
	int			i;
	t_lst_arg	*arg;
	t_lst_file	*file;

	i = 0;
	arg = NULL;
	file = NULL;
	while (prompt[i])
	{
		if (prompt[i] == '|')
			*cmd = *cmd->next;
		while (white_space(prompt[i]))
			i++;
		if (prompt[i] && !file(prompt[i]))
			fill_arg(prompt, &arg, *i);
		else if (prompt[i])
			fill_file(prompt, &file, *i);
		(*cmd)->arg = arg;
		(*cmd)->file = file;
	}
}
