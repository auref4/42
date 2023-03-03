#include "push_swap.h"

int	is_valid(char c)
{
	if ((c >= '0' && c <= '9') || c == ' ')
		return(1);
	else
		return(0);
}

int	check_arg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if(!is_valid(argv[i][j]))
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}
