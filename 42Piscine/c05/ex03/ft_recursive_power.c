/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:07:45 by auferran          #+#    #+#             */
/*   Updated: 2022/10/03 14:48:24 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{	
	if (power < 0)
	{
		return (0);
	}	
	if (power == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}

/*
int	main(void)
{
	int	x;
	int	nb;
	int	power;

	nb = 25;
	power = 5;
	x = ft_recursive_power(nb, power);
	printf("%d\n", x);
}
*/
