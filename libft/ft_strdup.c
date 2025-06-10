/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:55:44 by auferran          #+#    #+#             */
/*   Updated: 2022/11/10 19:58:07 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *source)
{
	char	*dest;
	size_t	i;

	i = ft_strlen(source);
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, (char *)source);
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*dest;
	char	*dest2;
	(void) argc;

	dest = ft_strdup(argv[1]);
	dest2 = strdup(argv[1]);
	printf("ft_strdup = %s\n", dest);
	printf("strdup = %s\n", dest2);
}
*/
