/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:33:20 by auferran          #+#    #+#             */
/*   Updated: 2022/09/27 15:42:21 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	nb;

	i = 0;
	signe = 0;
	nb = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{	
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (signe % 2 == 1)
	{
		nb = nb * -1;
	}	
	return (nb);
}

/*
int	main(int argc, char **argv)
{
	int	nb;
	(void) argc;

	nb = ft_atoi(argv[1]);
	printf("%d\n", nb);
}
*/
