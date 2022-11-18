/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:29:32 by sycourbi          #+#    #+#             */
/*   Updated: 2022/10/02 21:10:51 by minh-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../includes/ft.h"
#include <stdlib.h>

int	ft_check_key(char *str)
{
	if (*str != '1')
		return (0);
	str++;
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

char	*get_key(char *str)
{
	char	*c;
	int		i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	c = malloc(sizeof(char) * i + 1);
	if (!c)
		return (0);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
