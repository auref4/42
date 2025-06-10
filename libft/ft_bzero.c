/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:55:04 by auferran          #+#    #+#             */
/*   Updated: 2022/11/10 19:01:41 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <strings.h>

int	main(void)
{
	int	i;
	char	s1[5] = {1, 2, 3, 4, 5};
	char	s2[5] = {1, 2, 3, 4, 5};

	i = 0;
	ft_bzero(s1, 5);
	bzero(s2, 5);
	while (i < 5)
	{
		printf("ft_bzero = %d\nbzero = %d\n", s1[i], s2[i]);
		i++;
	}
}
*/
