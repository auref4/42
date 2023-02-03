int	ft_checkbase(int str_base, char c)
{
	int	i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	while (i < str_base)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	negate;
	int	nb;

	i = 0;
	negate = 0;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negate = 1;
		i++;
	}
	while (ft_checkbase(str_base, str[i]) != -1)
	{
		nb = nb * str_base + (ft_checkbase(str_base, str[i]));
		i++;
	}
	if (negate == 1)
		nb = nb * -1;
	return (nb);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void) argc;

	printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
}
*/
