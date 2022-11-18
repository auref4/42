/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh-ngu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:30:01 by minh-ngu          #+#    #+#             */
/*   Updated: 2022/10/02 20:50:18 by minh-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include<stdlib.h>

int	prefix(char **a_s, char *nbr, char *s, int n)
{
	if (n == 1)
		s = level1(a_s, nbr, s);
	if (n == 2)
		s = level2(a_s, nbr, s);
	if (n == 3)
		s = level3(a_s, nbr, s);
	if (!s)
		return (0);
	return (1);
}

int	get_number(char **a_s, char *nbr, char *s)
{
	int	n;
	int	n0;

	n = ft_strlen(nbr);
	n0 = n % 3;
	if (n % 3 == 0)
		n0 = 3;
	if (!prefix(a_s, nbr, s, n0))
		return (0);
	if (n >= 4)
	{
		s = triple0(a_s, &nbr[n0], s);
		if (!s)
			return (0);
		s = level(a_s, &nbr[n0], s);
		if (!s)
			return (0);
	}
	return (1);
}

int	ft_zero(char **a_s)
{
	char	*s1;

	s1 = ft_dict(a_s, "0");
	if (!s1)
		return (0);
	ft_putstr(1, s1);
	ft_putstr(1, "\n");
	free(s1);
	return (1);
}

int	ft_convert(char **a_s, char *nbr)
{
	char	*s;

	while (*nbr == '0')
		nbr++;
	if (!*nbr)
	{
		if (!ft_zero(a_s))
			return (0);
		return (1);
	}
	s = malloc(sizeof(char) * 10000);
	if (!s)
		return (0);
	s[0] = 0;
	if (!get_number(a_s, nbr, s))
	{
		free(s);
		return (0);
	}
	ft_putstr(1, s);
	ft_putstr(1, "\n");
	free(s);
	return (1);
}
