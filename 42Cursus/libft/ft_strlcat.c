/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:33:21 by auferran          #+#    #+#             */
/*   Updated: 2022/11/09 11:34:34 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lend;
	size_t	lens;

	i = 0;
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (size < lend)
		return (size + lens);
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && j < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[lend + i] = '\0';
	return (lend + lens);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

int	main(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	char	dst[2500] = "coucou, ca va ?";
	(void) argc;

	i = ft_strlcat(dst, argv[1], atoi(argv[2]));
	j = strlcat(dst, argv[1], atoi(argv[2]));
	printf("ft_strlcat = %ld\n", i);
	printf("strlcat = %ld\n", j);
}
*/
