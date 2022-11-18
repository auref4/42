/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:05:33 by auferran          #+#    #+#             */
/*   Updated: 2022/09/19 13:27:44 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
	i++;
	}
}

/*
int	main(void)
{
	char	str[] = "je fais un test\0";
	ft_putstr(str);
}

*/

/*
 
	AUTRE FACON DE FAIRE   	

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write (1, str, 1);
	str++;
	}
}

int	main(void)
{
	char	str[17] = "je fais un test!\0";
	ft_putstr(str);
	
}*/
