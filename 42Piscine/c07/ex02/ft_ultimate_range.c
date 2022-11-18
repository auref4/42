/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:27:04 by auferran          #+#    #+#             */
/*   Updated: 2022/10/04 18:27:38 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if (!*range)
	{	
		*range = NULL;
		return (0);
	}	
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (i);
}

/*
int	main(int argc, char **argv)
{
	int	*x;
	int	e;
	int	i;
	(void) argc;

	i = 0;
	e = ft_ultimate_range(&x, atoi(argv[1]), atoi(argv[2]));
	while (i < atoi(argv[2]) - atoi(argv[1]))
	{
		printf("%d\n", x[i]);
		i++;
	}
	printf("la taille = %d", e);
	free (x);	
}
*/
