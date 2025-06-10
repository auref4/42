/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:46:32 by auferran          #+#    #+#             */
/*   Updated: 2022/11/21 18:57:05 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *theString)
{
	int	i;
	int	signe;
	int	nb;

	signe = 0;
	i = 0;
	nb = 0;
	while ((theString[i] && (theString[i] >= '\t' && theString[i] <= '\r'))
		|| (theString[i] == ' '))
		i++;
	if ((theString[i] && theString[i] == '-') || theString[i] == '+')
	{
		if (theString[i] == '-')
			signe = 1;
		i++;
	}
	while (theString[i] && theString[i] >= '0' && theString[i] <= '9')
	{
		nb = nb * 10 + (theString[i] - 48);
		i++;
	}
	if (signe == 1)
		nb = nb * -1;
	return (nb);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	(void) argc;

	i = ft_atoi(argv[1]);
	j = atoi(argv[2]);
	printf("%d\n", i);
	printf("%d\n", j);
}
*/
