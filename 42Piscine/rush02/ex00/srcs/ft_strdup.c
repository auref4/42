/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh-ngu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:56:59 by minh-ngu          #+#    #+#             */
/*   Updated: 2022/10/02 21:09:40 by minh-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	len(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*o;
	char	*p;

	o = (char *) malloc(sizeof(char) * (len(src) + 1));
	if (!o)
		return (0);
	p = o;
	while (*src)
	{
		*o = *src;
		src++;
		o++;
	}
	*o = 0;
	return (p);
}
