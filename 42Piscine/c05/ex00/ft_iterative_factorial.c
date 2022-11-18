/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:22:25 by auferran          #+#    #+#             */
/*   Updated: 2022/10/03 13:04:14 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	i = 1;
	res = 1;
	if (nb < 0)
	{
		return (0);
	}
	while (i <= nb)
	{
		res = res * i;
		i++;
	}
	return (res);
}

/*
int	main(void)
{
	int	i;
	int	nb;

	nb = 4;
	i = ft_iterative_factorial(nb);
	printf("%d\n", i);

}
*/
