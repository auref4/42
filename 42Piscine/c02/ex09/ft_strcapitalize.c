/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:01:26 by auferran          #+#    #+#             */
/*   Updated: 2022/09/22 13:00:28 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_number(char c)
{	
	if (c >= '0' && c <= '9')
	{
		return (1);
	}	
	return (0);
}

int	ft_lowercase(char c)
{	
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}	

int	ft_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		str[i] = str[i] + 32;
		i++;
	}
	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (!ft_number(str[i - 1]) && !ft_uppercase(str[i - 1])
			&& !ft_lowercase(str[i - 1])
			&& (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}	

/*
int	main(int argc, char **argv)
{
	char	*str;

	argc = 1;
	str = ft_strcapitalize(argv[argc]);
	printf("%s", str);
}
*/
