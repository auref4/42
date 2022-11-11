/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:52:31 by auferran          #+#    #+#             */
/*   Updated: 2022/11/07 16:40:21 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *theString)
{
	size_t	i;

	i = 0;
	while (theString[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	(void) argc;

	i = ft_strlen(argv[1]);
	j = strlen(argv[2]);
	printf("%ld\n", i);
	printf("%ld\n", j);
}
*/
