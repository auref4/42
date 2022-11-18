/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:45:28 by auferran          #+#    #+#             */
/*   Updated: 2022/09/27 11:31:45 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}	

void	ft_putnbr(int nb)
{
	long long int	nb2;

	nb2 = nb;
	if (nb2 < 0)
	{	
		write (1, "-", 1);
		nb2 = nb2 * -1;
	}
	if (nb2 >= 10)
	{	
		ft_putnbr(nb2 / 10);
	}	
	ft_putchar(nb2 % 10 + 48);
}

/*
int	main(void)
{
	ft_putnbr(-2147483648);
	ft_putchar('\n');
        ft_putnbr(44);
}
*/
