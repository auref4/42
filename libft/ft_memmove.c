/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:37:00 by auferran          #+#    #+#             */
/*   Updated: 2022/11/10 18:59:56 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pdest;
	unsigned char	*psrc;

	i = 0;
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *) src;
	if (pdest > psrc)
	{
		while (n > 0)
		{
			pdest[n - 1] = psrc[n - 1];
			n--;
		}
		return (pdest);
	}
	else
	{
		while (i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
		return (pdest);
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*i;
	char	*j;
	(void) argc;

	i = ft_memmove(argv[1], argv[2], ft_atoi(argv[3]));
	j = memmove(argv[1], argv[2], ft_atoi(argv[3]));
	printf("ft_memmove = %s\nmemmove = %s\n", i, j);
}
*/
