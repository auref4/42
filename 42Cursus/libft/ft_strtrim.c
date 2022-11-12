/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:37:55 by auferran          #+#    #+#             */
/*   Updated: 2022/11/12 22:23:13 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	x;
	char	*dest;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && !check_set(s1[i], set))
		i++;
	while (s1[j] && !check_set(s1[j], set))
		j--;
	dest = malloc(sizeof(char) * (j - i + 1));
	if (!dest)
		return (NULL);
	x = 0;
	while (i <= j)
	{
		dest[x] = s1[i];
		x++;
		i++;
	}
	dest[x] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*s1;
	(void) argc;

	s1 = ft_strtrim(argv[1], argv[2]);
	printf("ft_strtrim = %s\n", s1);
}
*/
