/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:17:42 by auferran          #+#    #+#             */
/*   Updated: 2022/11/12 17:56:09 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;
	char	*t;

	if (s == NULL || start > ft_strlen(s) || len == 0)
		return (NULL);
	i = start;
	x = ft_strlen(&s[start]);
	t = malloc(sizeof(char) * (x + 1));
	if (!t)
		return (NULL);
	j = 0;
	while (s[i] && j < len)
	{
		t[j] = s[i];
		j++;
		i++;
	}
	t[j] = '\0';
	return (t);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*str;
	(void) argc;

	str = ft_substr(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	printf("ft_substr = %s\n", str);
}
*/
