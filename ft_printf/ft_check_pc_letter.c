/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pc_letter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:22:27 by auferran          #+#    #+#             */
/*   Updated: 2022/11/24 18:26:30 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_pc_letter(char c)
{
	int		i;
	char	*str;

	i = 0;
	str = "cspdiuxX%";
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d\n", ft_check_pc_letter(*argv[1]));
	return (0);
}
*/
