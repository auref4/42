/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh-ngu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:30:01 by minh-ngu          #+#    #+#             */
/*   Updated: 2022/10/02 21:19:03 by minh-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1

void	ft_free_read(char **a_s)
{
	char	**a_s0;

	a_s0 = a_s;
	while (*a_s)
	{
		free(*a_s);
		a_s++;
	}
	free(a_s0);
}

int	ft_count_lines(char *file_name)
{
	char	buf[BUF_SIZE + 1];
	int		i;
	int		fd;
	int		ret;

	fd = open(file_name, O_RDONLY);
	ret = 1;
	i = 0;
	while (ret)
	{
		ret = read(fd, buf, BUF_SIZE);
		if (buf[0] == '\n')
			i++;
	}
	return (i);
}

char	*get_string(int fd, int i, int j)
{
	char	*s;
	char	buf[BUF_SIZE + 1];

	s = malloc(sizeof(char) * (i - j));
	if (!s)
		printf("Allocation echouee");
	lseek(fd, -(i - j), SEEK_CUR);
	read(fd, s, i - j - 1);
	s[i - j - 1] = 0;
	read(fd, buf, 1);
	return (s);
}

void	ft_read_lines(int fd, char **a_s, int ret)
{
	int		i;
	int		j;
	int		k;
	char	buf[BUF_SIZE + 1];

	i = 0;
	j = 0;
	k = 0;
	while (ret)
	{
		ret = read(fd, buf, BUF_SIZE);
		i += ret;
		if (buf[0] == '\n')
		{
			if (i > j + 1)
			{
				a_s[k] = get_string(fd, i, j);
				k++;
			}
			j = i;
		}
		buf[ret] = 0;
	}
	a_s[k] = 0;
}

char	**ft_read(char *file_name)
{
	int		ret;
	int		fd;
	char	**a_s;

	a_s = malloc(sizeof(char *) * ft_count_lines(file_name));
	if (!a_s)
		return (0);
	fd = open(file_name, O_RDONLY);
	ret = 1;
	ft_read_lines(fd, a_s, ret);
	close(fd);
	return (a_s);
}
