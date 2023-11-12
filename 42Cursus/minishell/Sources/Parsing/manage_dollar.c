#include "minishell.h"

int	search_and_count_env(char *prompt, int *i, t_struct_strdup *s)
{
	t_lst_env	*tmp;

	tmp = s->lst_env;
	while (tmp)
	{
		if (cmp_env(prompt, i, tmp->line))
		{
			count_env(tmp->line, s);
			(*i)--;
			return (1);
		}
		tmp = tmp->next;
	}
	(*i)++;
	while (prompt[*i] && its_valid_expand(prompt[*i]))
		(*i)++;
	(*i)--;
	s->env_type = 1;
	return (0);
}

int	check_dollar_count(char *prompt, int *i, t_struct_strdup *s)
{
	if (in_quote(prompt, *i, &s->s_q, &s->d_q) && s->s_q == 1)
		return (0) ;
	if (prompt[*i] == '$' && (!prompt[*i + 1] || !its_valid_expand(prompt[*i + 1])))
		return (0);
	else if (!search_and_count_env(prompt, i, s))
		return (-1) ;
	return (1);
}

int	search_and_expand_env(char *prompt, int *i, t_struct_strdup *s)
{
	t_lst_env	*tmp;

	tmp = s->lst_env;
	while (tmp)
	{
		if (cmp_env(prompt, i, tmp->line))
		{
			expand(s, tmp->line);
			(*i)--;
			return (1);
		}
		tmp = tmp->next;
	}
	(*i)++;
	while (prompt[*i] && its_valid_expand(prompt[*i]))
		(*i)++;
	(*i)--;
	return (0);
}

int	check_dollar_expand(char *prompt, int *i, t_struct_strdup *s)
{
	if (in_quote(prompt, *i, &s->s_q, &s->d_q) && s->s_q == 1)
		return (0) ;
	if (prompt[*i] == '$' && (!prompt[*i + 1] || !its_valid_expand(prompt[*i + 1])))
		return (0);
	else if (!search_and_expand_env(prompt, i, s))
		return (-1) ;
	return (1);
}
