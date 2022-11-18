/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:35:16 by auferran          #+#    #+#             */
/*   Updated: 2022/11/16 20:53:24 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(src);
	if (size == 0)
		return (j);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

int	main(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	char	dst[2500];
	(void) argc;

	i = ft_strlcpy(dst, argv[1], atoi(argv[2]));
	j = strlcpy(dst, argv[1], atoi(argv[2]));
	printf("ft_strlcpy = %ld\n", i);
	printf("strlcpy = %ld\n", j);
}
*/
