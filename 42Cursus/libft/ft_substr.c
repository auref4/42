/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:17:42 by auferran          #+#    #+#             */
/*   Updated: 2022/11/11 17:53:46 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*t;

	i = 0;
	if (len == 0)
		return (NULL);
	t = malloc(sizeof(char) * len + 1);
	if (!t)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char const)start)
		{
			j = 0;
			while (s[i] && j < len)
			{
				t[j++] = s[i++];
			}
			t[j] = '\0';
			return (t);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*str;
	(void) argc;

	str = ft_substr(argv[1], *argv[2], ft_atoi(argv[3]));
	printf("ft_substr = %s\n", str);
}
*/
