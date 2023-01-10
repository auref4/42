/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:25:07 by auferran          #+#    #+#             */
/*   Updated: 2023/01/09 19:55:51 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*save;
	int		r;
	int		n;
	(void)	r;

	line = NULL;
	n = -1;
	while (4)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		r = read(fd, buff, BUFFER_SIZE);
		buff[r] = '\0';
		if (save)
			save = ft_strjoin(save, buff);
		else
			save = buff;
		if (save)
			n = ft_strchr(save, '\n');
		if (n >= 0)
		{
			line = ft_substr(save, 0, n + 1);
			save = ft_substr(&save[n + 1], 0, ft_strlen(&save[n + 1]));
			return (line);
		}
		if (r <= 0 || r < BUFFER_SIZE)
			return (ft_strdup(&save));
		if (n <= 0)
		{
			line = ft_strdup(buff);
			return (line);
		}
		if (r <= 0 || r < BUFFER_SIZE)
		{
			buff = NULL;
			return (ft_strdup(buff));
		}
		return (NULL);
	}
	return (NULL);
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	int	a;
	char	*line;

	a = 1;
	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line = %s", line);
		free (line);
	}
/*	while (a)
	{
		line = get_next_line(fd);
		printf("testdefoufurieux = %s", line);
		if (line == NULL)
			a = 0;
		free(line);
	} */
	return (0);
}
