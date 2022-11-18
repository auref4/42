/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:50:21 by auferran          #+#    #+#             */
/*   Updated: 2022/09/28 18:17:44 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}	

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_checkbase(char *base)
{
	int	i;

	i = 0;
	if (ft_strlen(base) < 2)
	{	
		return (0);
	}
	while (base[i] != '\0')
	{
		if (((base[i] >= '\t' && base[i] <= '\r') || base[i] == ' ')
			|| (base[i] == '+' || base[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkbase2(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j] != '\0')
		{	
			if (base[i] == base[j])
			{	
				return (0);
			}	
			j++;
		}
		i++;
	}	
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long int	nbr2;
	int				base_len;

	base_len = ft_strlen(base);
	nbr2 = nbr;
	if (ft_checkbase(base) == 0)
	{
		return ;
	}
	if (ft_checkbase2(base) == 0)
	{
		return ;
	}	
	if (nbr2 < 0)
	{
		write (1, "-", 1);
		nbr2 = nbr2 * -1;
	}
	if (nbr2 >= base_len)
	{
		ft_putnbr_base(nbr2 / base_len, base);
	}
	ft_putchar(base[nbr2 % base_len]);
}

/*
int	main(int argc, char **argv)
{
	int i = atoi(argv[1]);
	(void) argc;
	ft_putnbr_base(i, argv[2]);
}
*/
