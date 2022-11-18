/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:05:14 by auferran          #+#    #+#             */
/*   Updated: 2022/11/10 18:59:06 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)pointer;
	while (p[i] && i < count)
	{
		p[i] = value;
		i++;
	}
	return (pointer);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	unsigned char *pointer;
	unsigned char *pointer2;
	(void) argc;

	pointer = ft_memset(argv[1], 'A', 4);
	pointer2 = memset(argv[1], 'A', 4);
	printf("%s\n", pointer);
	printf("%s\n", pointer2);
}
*/
