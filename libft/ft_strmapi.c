/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:04:51 by auferran          #+#    #+#             */
/*   Updated: 2022/11/22 20:31:24 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*dest;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

char	f(unsigned int i, char c)
{
	char	x;
	(void) i;

	x = c - 32;
	return (x);
}

int	main(int argc, char **argv)
{
	char	*dest;
	(void) argc;

	dest = ft_strmapi(argv[1], f);
	printf("ft_strmapi = %s\n", dest);
}
*/
