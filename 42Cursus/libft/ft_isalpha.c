/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:26:26 by auferran          #+#    #+#             */
/*   Updated: 2022/11/08 14:45:58 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int character)
{
	if ((character >= 'A' && character <= 'Z')
		|| (character >= 'a' && character <= 'z'))
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

	i = ft_isalpha(atoi(argv[1]));
	j = isalpha(atoi(argv[1]));
	printf("%d\n", i);
	printf("%d\n", j);
}
*/
