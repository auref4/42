/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:11:30 by auferran          #+#    #+#             */
/*   Updated: 2023/03/17 23:51:14 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	jump_whitespace_sign(const char *s, int *i, int *sign)
{
	while ((s[*i] && (s[*i] >= '\t' && s[*i] <= '\r')) || (s[*i] == ' '))
		(*i)++;
	if ((s[*i] == '-' ) || (s[*i] == '+'))
	{
		if (s[*i] == '-')
			(*sign)++;
		(*i)++;
	}
}

int	ft_atoi(const char *s, int *nb)
{
	int		i;
	int		sign;
	long	max;
	long	nbr;

	i = 0;
	sign = 0;
	max = INT_MAX;
	nbr = 0;
	jump_whitespace_sign(s, &i, &sign);
	while (s[i] && (s[i] >= '0' && s[i] <= '9') && (nbr <= max + 2))
	{
		nbr = nbr * 10 + (s[i] - 48);
		i++;
	}
	if (sign == 1)
		nbr = nbr * -1;
	if (nbr < INT_MIN || nbr > INT_MAX)
	{
		ft_error();
		return (0);
	}
	*nb = nbr;
	return (1);
}
