/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:21:40 by auferran          #+#    #+#             */
/*   Updated: 2022/09/29 18:54:07 by auferran         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}	

int	main(int argc, char **argv)
{
	int	j;
	int	x;

	j = 1;
	while (j < argc - 1)
	{
		x = ft_strcmp(argv[j], argv[j + 1]);
		if (x > 0)
		{
			ft_swap(&argv[j], &argv[j + 1]);
			j = 0;
		}	
		j++;
	}
	j = 1;
	while (argv[j])
	{
		ft_putstr(argv[j]);
		write (1, "\n", 1);
		j++;
	}	
}
