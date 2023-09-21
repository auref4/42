#include "minishell.h"

int	count_quote(char *str, int nb)
{
	int	i;
	int	nb_quote;
	int	type_quote;

	i = 0;
	nb_quote = 0;
	type_quote = 0;
	if (nb == SINGLE_QUOTE)
		type_quote = 39;
	if (nb == DOUBLE_QUOTE)
		type_quote = 34;
	while (str[i])
	{
		if (str[i] == type_quote)
			nb_quote++;
		i++;
	}
	return(nb_quote);
}

void	value_in_quote(int booleen1, int booleen2, int *value1, int *value2)
{
	if (booleen1 == 1 && *value1 == 0)
		*value1 += 1;
	if (booleen2 == 1 && *value2 == 0)
		*value2 += 1;
	if (booleen1 == 0 && *value1 == 1)
		*value1 -= 1;
	if (booleen2 == 0 && *value2 == 1)
		*value2 -= 1;
}

void	swap_booleen(int *booleen)
{
	if (*booleen == 0)
		*booleen += 1;
	else if (*booleen == 1)
		*booleen -= 1;
}

int	in_quote(char *str, int c, int *in_s_quote, int *in_d_quote)
{
	t_struct_quote	s;

	if (!str)
		return(-1);
	ft_memset(&s, 0, sizeof(t_struct_quote));
	while (str[s.i])
	{
		if (str[s.i] == '\'' && s.s_quote == 0)
			swap_booleen((&s.s_quote));
		if (str[s.i] == '"' && s.d_quote == 0)
			swap_booleen((&s.d_quote));
		printf("s_quote = %d\n", s.s_quote);
		printf("d_quote = %d\n", s.d_quote);
		if (s.i == c && (s.s_quote == 1 || s.d_quote == 1))
		{
			value_in_quote(s.s_quote, s.d_quote, in_s_quote, in_d_quote);
			return (1);
		}
		if (str[s.i] == '\'' && s.s_quote == 1)
			swap_booleen((&s.s_quote));
		if (str[s.i] == '"' && s.d_quote == 1)
			swap_booleen((&s.d_quote));
		s.i++;
	}
	return (0);
}
