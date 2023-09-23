#include "minishell.h"

int	white_space(char c)
{
	if (c == ' ' || c == '\r' || c == '\t')
		return (1);
	return (0);
}

int	file(char c)
{
	if (c == '<')
		return (1);
	if (c == '>')
		return (2);
	return (0);
}
