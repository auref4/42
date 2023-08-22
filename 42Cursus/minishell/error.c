#include "minishell.h"

void	error(int nb)
{
	if (nb == ERROR_MALLOC)
		printf("Malloc Failure ?\n");
	if (nb == ERROR_PROMPT)
		printf("Error syntax ?\n");
}
