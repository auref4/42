/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:56:18 by auferran          #+#    #+#             */
/*   Updated: 2022/11/11 15:21:30 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t lenght)
{
	size_t	i;

	i = 0;
	if (lenght == 0)
		return (0);
	while (first[i] && second[i] && first[i] == second[i] && i < lenght - 1)
		i++;
	return (first[i] - second[i]);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	(void) argc;

	i = ft_strncmp(argv[1], argv[2], atoi(argv[3]));
	j = strncmp(argv[1], argv[2], atoi(argv[3]));
	printf("%d\n", i);
	printf("%d\n", j);
}
*/
