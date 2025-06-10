/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:02:51 by auferran          #+#    #+#             */
/*   Updated: 2022/11/21 17:48:12 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*p;

	if (size != 0 && nmemb > SIZE_MAX / size)
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

int	main(void)
{

	unsigned int	*p1;
	unsigned int	*p2;

	p1 = ft_calloc(922337203685477580, 2);
	p2 = calloc(922337203685477580, 2);
	printf("ft_calloc = %p\ncalloc = %p\n", p1, p2);
	free (p1);
	free (p2);
}
*/
