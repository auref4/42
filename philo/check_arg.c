/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:03:07 by auferran          #+#    #+#             */
/*   Updated: 2023/06/23 19:03:38 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_withespace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_arg(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		if (argv[j][i] == '\0')
			return (0);
		while (argv[j][i])
		{
			if (is_digit(argv[j][i]) || is_withespace(argv[j][i])
				|| argv[j][i] == '+' || argv[j][i] == '-')
				i++;
			else
				return (0);
		}
	j++;
	}
	return (1);
}
