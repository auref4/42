/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:51:55 by auferran          #+#    #+#             */
/*   Updated: 2022/11/16 21:12:03 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (searchedChar == string[i])
			return ((char *)&string[i]);
		i++;
	}
	if (!searchedChar)
		return ((char *)&string[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*a;
	char	*b;
	(void) argc;

	a = ft_strchr(argv[1], atoi(argv[2]));
	b = strchr(argv[1], atoi(argv[2]));
	printf("ft_strchr = %s\n", a);
	printf("strchr = %s\n", b);
}
*/
