/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:56:18 by auferran          #+#    #+#             */
/*   Updated: 2022/11/16 19:24:09 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t lenght)
{
	size_t			i;
	unsigned char	*ufirst;
	unsigned char	*usecond;

	ufirst = (unsigned char *)first;
	usecond = (unsigned char *)second;
	i = 0;
	if (lenght == 0)
		return (0);
	while (ufirst[i] && usecond[i] && ufirst[i] == usecond[i] && i < lenght - 1)
		i++;
	return (ufirst[i] - usecond[i]);
}
/*
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int	i;
	int	j;

	i = ft_strncmp("test\200", "test\0", 6);
	j = strncmp("test\200", "test\0", 6);
	printf("%d\n", i);
	printf("%d\n", j);
}
*/
