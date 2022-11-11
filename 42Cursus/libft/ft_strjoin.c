/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:30:36 by auferran          #+#    #+#             */
/*   Updated: 2022/11/11 18:22:43 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	lens1;
	size_t	lens2;
	char	*dest;
	char	*cat;

	i = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (lens1 + lens2) + 1);
	if (!dest)
		return (NULL);
	cat = ft_strcat((char *)s1, (char *)s2);
	while (cat[i])
	{
		dest[i] = cat[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*s1;

	if (argc == 3)
	{
		s1 = ft_strjoin(argv[1], argv[2]);
		printf("ft_strjoin = %s\n", s1);
	}
	else
		return (0);
}
*/
