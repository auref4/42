/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:54:25 by auferran          #+#    #+#             */
/*   Updated: 2022/11/08 14:44:35 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int character)
{
	if ((character >= 'A' && character <= 'Z')
		|| (character >= 'a' && character <= 'z'))
		return (1);
	else if (character >= '0' && character <= '9')
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

	i = ft_isalnum(atoi(argv[1]));
	j = isalnum(atoi(argv[2]));
	printf("%d\n", i);
	printf("%d\n", j);
}
*/
