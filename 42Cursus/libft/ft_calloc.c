/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:02:51 by auferran          #+#    #+#             */
/*   Updated: 2022/11/16 20:23:15 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*p;

	if (size == 0 || nmemb > SIZE_MAX / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	unsigned int	*p1;
	unsigned int	*p2;
	(void) argc;

	i = 0;
	p1 = ft_calloc(atoi(argv[1]), sizeof(int));
	p2 = calloc(atoi(argv[1]), sizeof(int));
	while (i < atoi(argv[1]))
	{
		printf("ft_calloc = %d\ncalloc = %d\n", p1[i], p2[i]);
		i++;
	}
}
*/
