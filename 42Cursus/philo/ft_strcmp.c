/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:20:39 by auferran          #+#    #+#             */
/*   Updated: 2023/07/09 16:20:41 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(const char *first, const char *second)
{
	size_t			i;
	unsigned char	*ufirst;
	unsigned char	*usecond;

	i = 0;
	ufirst = (unsigned char *)first;
	usecond = (unsigned char *)second;
	while (ufirst[i] && usecond[i] && ufirst[i] == usecond[i])
		i++;
	return (ufirst[i] - usecond[i]);
}
