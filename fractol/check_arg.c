/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:41:51 by auferran          #+#    #+#             */
/*   Updated: 2023/03/23 03:24:01 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	check_arg(char **argv)
{
	char	*mand;
	char	*julia;
	char	*deux;
	char	*trois;

	mand = "Mandelbrot";
	julia = "Julia";
	deux = "2";
	trois = "3";
	if (!ft_strcmp(argv[1], mand) && !argv[2])
		return (1);
	else if (!ft_strcmp(argv[1], julia) && !argv[2])
		return (2);
	else if (!ft_strcmp(argv[1], julia) && !ft_strcmp(argv[2], deux))
		return (3);
	else if (!ft_strcmp(argv[1], julia) && !ft_strcmp(argv[2], trois))
		return (4);
	return (0);
}
