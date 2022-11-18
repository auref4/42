/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:49:08 by auferran          #+#    #+#             */
/*   Updated: 2022/10/04 00:06:01 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	i = 0;
	if (min >= max)
	{	
		tab = NULL;
		return (tab);
	}	
	tab = malloc(sizeof (int) * (max - min));
	if (!tab)
		return (NULL);
	while (min < max)
	{	
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
/*
int	main(int argc, char **argv)
{
	int	*tab;
	int	i;
	(void) argc;

	i = 0;
	tab = ft_range(atoi(argv[1]), atoi(argv[2]));
	while (i < atoi(argv[2]) - atoi(argv[1]))
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
*/
