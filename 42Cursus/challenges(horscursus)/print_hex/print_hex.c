#include <unistd.h>

int	ft_atoi(char *str)
{
	int	nb;
	int	negate;
	int	i;

	nb = 0;
	negate = 0;
	i = 0;
	while ((str[i] && (str[i] >= '\t' && str[i] <= '\r')) || (str[i] == ' '))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negate = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (negate == 1)
		nb = nb * -1;
	return (nb);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(int nb)
{
	if (nb >= 16)
		ft_print_hex(nb / 16);
	if ((nb % 16) < 10)
		ft_putchar((nb % 16) + 48);
	else
		ft_putchar((nb % 16) - 10 + 'a');
}

int	main(int argc, char **argv)
{
	int	nb ;

	if (argc == 2)
	{
		nb = ft_atoi(argv[1]);
		ft_print_hex(nb);
	}
	write (1, "\n", 1);
}
