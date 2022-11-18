/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:21:43 by auferran          #+#    #+#             */
/*   Updated: 2022/11/10 16:20:18 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	(void) argc;

	i = ft_memcmp(argv[1], (argv[2]), ft_atoi(argv[3]));
	j = memcmp(argv[1], (argv[2]), ft_atoi(argv[3]));
	printf("ft_memcmp = %d\nmemcmp = %d\n", i, j);
}
*/
