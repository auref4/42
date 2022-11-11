/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:31:38 by auferran          #+#    #+#             */
/*   Updated: 2022/11/09 11:32:48 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bsd/string.h>

int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	(void) argc;

	s1 = ft_strnstr(argv[1], argv[2], atoi(argv[3]));
	s2 = strnstr(argv[1], argv[2], atoi(argv[3]));
	printf("ft_strnstr = %s\n", s1);
	printf("strnstr = %s\n", s2);
}
*/
