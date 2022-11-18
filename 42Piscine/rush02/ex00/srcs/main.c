/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:39:56 by auferran          #+#    #+#             */
/*   Updated: 2022/10/02 20:57:00 by minh-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../includes/ft.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_check_error(char *str)
{	
	int	i;

	if (!*str)
		return (0);
	if (!(str[0] == '+' || (str[0] >= '0' && str[0] <= '9')))
		return (0);
	i = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}	

int	ft_check_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	close(fd);
	return (fd);
}

int	ft_check_args(int argc, char **argv, char **s, char **fn)
{
	char	*error;

	error = "Error\n";
	if (argc < 2 || argc > 3)
	{
		ft_putstr(2, error);
		return (0);
	}
	*s = argv[1];
	if (argc == 3)
	{
		*s = argv[2];
		if (ft_check_file(argv[1]) == -1)
		{
			ft_putstr(2, "Dict Error\n");
			return (0);
		}
		*fn = argv[1];
	}
	if (!ft_check_error(*s))
	{
		ft_putstr(2, error);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*s;
	char	*fn;
	char	**a_s;

	fn = "data/numbers.dict";
	if (!ft_check_args(argc, argv, &s, &fn))
		return (1);
	if (s[0] == '+')
		s = &s[1];
	a_s = ft_read(fn);
	if (!a_s)
		return (1);
	if (ft_strlen(s) > ft_max_len(a_s) + 2)
	{
		ft_free_read(a_s);
		ft_putstr(2, "Dict Error\n");
		return (1);
	}
	if (!ft_convert(a_s, s))
	{
		ft_free_read(a_s);
		ft_putstr(2, "Dict Error\n");
		return (1);
	}
	ft_free_read(a_s);
}
