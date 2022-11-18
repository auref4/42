/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:44:34 by auferran          #+#    #+#             */
/*   Updated: 2022/10/03 14:08:28 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	while (power > 0)
	{
		res = res * nb;
		power--;
	}
	return (res);
}

/*
int	main(void)
{
	int	x;
	int	nb;
	int	power;

	nb = 25;
	power = 5;
	x = ft_iterative_power(nb, power);
	printf("%d\n", x);
}
*/
