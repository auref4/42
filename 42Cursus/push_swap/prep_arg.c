#include "push_swap.h"

int	nb_words(char **argv)
{
	int	i;
	int	j;
	int	words;

	i = 1;
	words = 0;
	while (argv[i])
	{
		j = 0;
		if (is_digit(argv[i][j]))
		{
				words++;
				j++;
		}
		while (argv[i][j])
		{
			if (argv[i][j] == ' ' && is_digit(argv[i][j + 1]))
				words++;
			j++;
		}
		i++;
	}
	return (words);
}

void	dest_add_back(char **dest, char *tmp)
{
	int	i;

	if (!tmp)
		return ;
	*dest = malloc(sizeof(char) * ft_strlen(tmp) + 1);
	if (!(*dest))
	{
		free_dest(dest);
		return ;
	}
	i = 0;
	while (tmp[i])
	{
		(*dest)[i] = tmp[i];
		i++;
	}
	(*dest)[i] = '\0';
}

void	split_and_add_back(char **argv, char ***dest)
{
	int	i;
	int	j;
	int	x;
	char **tmp;

	i = 1;
	x = 0;
	while (argv[i])
	{
		tmp = NULL;
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return ;
		j = 0;
		while (tmp[j])
		{
			dest_add_back(&(*dest)[x], tmp[j]);
			j++;
			x++;
		}
		free_dest(tmp);
		i++;
	}
}

char	**prep_arg(char **argv)
{
	char **dest;

	dest = NULL;
	if (!argv)
		return (NULL);
	dest = ft_calloc(nb_words(argv) + 1, sizeof(char *));
	if (!dest)
		return (NULL);
	split_and_add_back(argv, &dest);
	return (dest);
}
