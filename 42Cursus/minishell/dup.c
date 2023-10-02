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

int	dup_in_quote(char *prompt, t_struct_strdup *s, int *i)
{
	while (in_quote(prompt, *i, &s->in_s_quote, &s->in_s_quote))
	{
		(*i)++;
		s->len++;
	}
	s->str = malloc(sizeof(char) * s->len + 1);
	if (!s->str)
		return (error("MALLOC FAILURE\n"), 0);
	*i -= s->len;
	while (prompt[*i] && !its_white_space(prompt[*i]))
		s->str[s->j++] = prompt[(*i)++];
	s->str[s->j] = 0;
	return (1);
}

int	dup_no_quote(char *prompt, t_struct_strdup *s, int *i)
{
	while (prompt[*i] && prompt[*i] != '|' && !its_white_space(prompt[*i]))
	{
		(*i)++;
		s->len++;
	}
	s->str = malloc(sizeof(char) * s->len + 1);
	if (!s->str)
		return (error("MALLOC FAILURE\n"), 0);
	*i -= s->len;
	while (prompt[*i] && !its_white_space(prompt[*i]))
		s->str[s->j++] = prompt[(*i)++];
	s->str[s->j] = 0;
	return (1);
}

char	*ft_strdup(char *prompt, char c, int *i, int nb)
{
	t_struct_strdup	s;

	ft_memset(&s, 0, sizeof(t_struct_strdup));
	if (nb == FILE)
		if (!count_c(prompt, c, i))
			return (NULL);
	while (prompt[*i] && its_white_space(prompt[*i]))
		(*i)++;
	if (in_quote(prompt, *i, &s.in_s_quote, &s.in_s_quote))
	{
		if (!dup_in_quote(prompt, &s, i))
			return (NULL);
	}
	else
		if (!dup_no_quote(prompt, &s, i))
			return (NULL);
	return (s.str);
}
