/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:09:57 by auferran          #+#    #+#             */
/*   Updated: 2022/09/19 14:21:30 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
	i++;
	}
	return (i);
}

/*
int	main(void)
{
	char    *str = "je fais un test\0";
	int	i;

	i = ft_strlen(str);
	printf("%d\n", i);
}
*/
