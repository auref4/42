/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:09:27 by auferran          #+#    #+#             */
/*   Updated: 2022/11/21 20:12:59 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *) s;
	while (i < n)
	{
		if (s1[i] == (unsigned char)c)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
//	char	*s1;
//	char	*s2;
	//(void) argc;

	//s1 = ft_memchr(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	//s2 = memchr(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	//printf("ft_memchr = %s\nmemchr = %s\n", s1, s2);
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("%s\n", (char *)ft_memchr(tab, -1, 7));
	printf("%s\n", (char *)memchr(tab, -1, 7));
}
*/
