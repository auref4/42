/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:09:27 by auferran          #+#    #+#             */
/*   Updated: 2022/11/10 16:20:21 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *) s;
	while (s1 && i < n)
	{
		if (c == s1[i])
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	(void) argc;

	s1 = ft_memchr(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	s2 = memchr(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	printf("ft_memchr = %s\nmemchr = %s\n", s1, s2);
}
*/
