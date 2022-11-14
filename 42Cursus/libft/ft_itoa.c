/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:58:34 by auferran          #+#    #+#             */
/*   Updated: 2022/11/14 20:30:24 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nb_recurs(long long int nb, int size, char *dest)
{
	size -= 1;
	if (nb > 0)
		nb_recurs(nb / 10, size, dest);
	dest[size] = nb % 10 + 48;
}

static void	nb_size(long long int nb, int *size)
{
	if (nb == 0)
		*size = 1;
	while (nb)
	{
		(*size)++;
		nb = nb / 10;
	}
}

char	*ft_itoa(int n)
{
	long long int	nb;
	int				size;
	int				negate;
	char			*dest;

	nb = n;
	negate = 0;
	size = 0;
	if (nb < 0)
	{
		size++;
		negate = 1;
		nb = nb * -1;
	}
	nb_size(nb, &size);
	dest = malloc(sizeof(char) * (size + 1));
	nb_recurs(nb, size, dest);
	if (nb == 0)
		dest[0] = '0';
	if (negate == 1)
		dest[0] = '-';
	dest[size] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	char	*s1;
	(void) argc;

	s1 = ft_itoa(ft_atoi(argv[1]));
	printf("ft_itoa = %s\n", s1);
	printf("%d\n", INT_MAX);
}
*/
