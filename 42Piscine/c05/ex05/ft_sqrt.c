/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:32:29 by auferran          #+#    #+#             */
/*   Updated: 2022/10/03 16:03:41 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (nb > i * i && i < 46340)
	{
		i++;
	}
	if (nb == i * i)
	{
		return (i);
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	int	i;

	i = atoi(argv[1]);
	if(argc == 2)
		printf("%d\n", ft_sqrt(i));
}
*/
