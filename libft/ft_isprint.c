/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:55:15 by auferran          #+#    #+#             */
/*   Updated: 2022/11/10 14:25:46 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int character)
{
	if (character >= 32 && character <= 126)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	(void) argc;

	i = ft_isprint(atoi(argv[1]));
	j = isprint(atoi(argv[1]));
	printf("%d\n", i);
	printf("%d\n", j);
}
*/
