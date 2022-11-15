/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:46:57 by auferran          #+#    #+#             */
/*   Updated: 2022/11/15 12:20:34 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

void	f(unsigned int, char *c)
{

	*c = *c + 13;
}

int	main(void)
{
	char	dest[] = "abcde";

	ft_striteri(dest, f);
	printf("ft_striteri = %s", dest);
}
*/
