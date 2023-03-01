/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:58:27 by auferran          #+#    #+#             */
/*   Updated: 2023/03/01 03:39:34 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)pointer;
	while (i < count)
	{
		p[i] = (unsigned char)value;
		i++;
	}
	return (pointer);
}

void	join_and_write(t_lst **lst, char **str)
{
	*str = ft_lst_join(&(*lst));
	ft_putstr(*str);
	ft_putchar('\n');
	ft_lst_clear(lst);
	free(*str);
	*str = NULL;
}
