/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:54:22 by auferran          #+#    #+#             */
/*   Updated: 2023/03/01 03:48:29 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_error(int nb)
{
	if (nb == 1)
		ft_putstr("le nombre d'arguments est incorrect.\n");
	if (nb == 2)
		ft_putstr("le pid ne peut pas etre un unsigned int.\n");
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
}

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
