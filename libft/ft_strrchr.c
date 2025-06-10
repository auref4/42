/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:52:47 by auferran          #+#    #+#             */
/*   Updated: 2022/11/21 19:02:33 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	i;

	i = ft_strlen(string);
	if (!searchedChar)
		return ((char *)&string[i]);
	i--;
	while (i >= 0)
	{
		if (string[i] == (const char)searchedChar)
			return ((char *)&string[i]);
		i--;
	}
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

	a = ft_strrchr(argv[1], atoi(argv[2]));
	b = strrchr(argv[1], atoi(argv[2]));
	printf("ft_strrchr = %s\n", a);
	printf("strrchr = %s\n", b);
}
*/
