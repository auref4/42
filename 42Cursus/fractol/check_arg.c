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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *first, const char *second, size_t lenght)
{
	size_t			i;
	unsigned char	*ufirst;
	unsigned char	*usecond;

	i = 0;
	ufirst = (unsigned char *)first;
	usecond = (unsigned char *)second;
	if (lenght == 0)
		return (0);
	while (ufirst[i] && usecond[i] && ufirst[i] == usecond[i] && i < lenght - 1)
		i++;
	return (ufirst[i] - usecond[i]);
}

int	check_arg(char **argv)
{
	char	*mand;
	char	*julia;

	mand = "Mandelbrot";
	julia = "Julia";
	if (ft_strlen(argv[1]) > ft_strlen(mand))
		return (0);
	if (ft_strlen(argv[1]) > ft_strlen(julia))
		return (0);
	if (!ft_strncmp(argv[1], mand, ft_strlen(mand)))
		return (1);
	if (!ft_strncmp(argv[1], julia, ft_strlen(julia)))
		return (2);
	return (0);
}
