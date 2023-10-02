#include "minishell.h"

int	count_c(char *prompt, char c, int *i)
{
	int	count;

	count = 0;
	while (prompt[*i] && prompt[*i] == c)
	{
		count++;
		(*i)++;
	}
	if (count > 2)
		return (error("minishell: syntax error near unexpected token\n"), 0);
	return (1);
}

char	*dup_file(char *prompt, char c, int *i)
{
	t_struct_dup_file	s;

	ft_memset(&s, 0, sizeof(t_struct_dup_file));
	if (!count_c(prompt, c, i))
		return (NULL);
	while (prompt[*i] && its_white_space(prompt[*i]))
		(*i)++;
	while (prompt[*i] && prompt[*i] != '|' && !its_white_space(prompt[*i]))
	{
		(*i)++;
		s.len++;
	}
	s.str = malloc(sizeof(char) * s.len + 1);
	if (!s.str)
		return (error("MALLOC FAILURE\n"), NULL);
	*i -= s.len;
	while (prompt[*i] && !its_white_space(prompt[*i]))
		s.str[s.j++] = prompt[(*i)++];
	s.str[s.j] = 0;
	return (s.str);
}

char	*dup_arg(char *prompt, int *i)
{
	t_struct_dup_arg	s;

	ft_memset(&s, 0, sizeof(t_struct_dup_arg));
	while (prompt[*i] && its_white_space(prompt[*i]))
		(*i)++;
	s.len = 0;
	while (prompt[*i] && prompt[*i] != '|' && !its_white_space(prompt[*i]))
	{
		s.len++;
		(*i)++;
	}
	s.str = malloc(sizeof(char) * s.len + 1);
	if (!s.str)
		return (error("MALLOC FAILURE\n"), NULL);
	s.j = 0;
	*i -= s.len;
	while (prompt[*i] && prompt[*i] != '|' && !its_white_space(prompt[*i]))
		s.str[s.j++] = prompt[(*i)++];
	s.str[s.j] = 0;
	return (s.str);
}
