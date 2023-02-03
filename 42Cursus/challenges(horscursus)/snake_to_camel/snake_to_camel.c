#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_count_underscore(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(str[i])
	{
		if (str[i] && str[i + 1] == '_')
			j++;
		i++;
	}
	return (j);
}

char	*ft_change_str(char *str)
{
	int	i;
	int	j;
	int	underscore;
	char	*dest;

	i = 0;
	while (str[i])
	{
		if (str[i] == '_' && (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
			str[i + 1] -= 32;
		i++;
	}
	underscore = ft_count_underscore(str);
	dest = malloc(sizeof(char) * (ft_strlen(str) - underscore) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '_')
		{
			dest[j] = str[i];
			j++;
		}
	i++;
	}
	return (dest);
}

int	main(int argc, char **argv)
{
	char	*dest;

	if (argc == 2)
	{
		dest = ft_change_str(argv[1]);
		ft_putstr(dest);
		free (dest);
	}
	ft_putchar('\n');
}
