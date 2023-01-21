/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:52:22 by auferran          #+#    #+#             */
/*   Updated: 2023/01/21 03:53:53 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*verif_n(int n, char **save)
{
	char	*line;
	char	*tmp;

	line = NULL;
	line = ft_substr(*save, 0, n + 1);
	if (!line)
		return (NULL);
	tmp = ft_substr(&(*save)[n + 1], 0, ft_strlen(&(*save)[n + 1]));
	if (!tmp)
		return (NULL);
	free(*save);
	*save = tmp;
	return (line);
}

int	verif_read(char *buff, char **save, int fd, int *r)
{
	*r = read(fd, buff, BUFFER_SIZE);
	if (*r <= 0 && !*save)
	{
		free(buff);
		return (0);
	}
	buff[*r] = '\0';
	return (1);
}

char	*verif_save(char **save, char *buff)
{
	*save = ft_strjoin(*save, buff);
	if (!*save)
		return (NULL);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*save[1024];
	int			r;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n = -1;
	while (4)
	{
		if (save[fd])
			n = ft_strchr(save[fd], '\n');
		if (n >= 0)
			return (verif_n(n, &save[fd]));
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff || !verif_read(buff, &save[fd], fd, &r))
			return (NULL);
		if (save[fd])
			verif_save(&save[fd], buff);
		else
			save[fd] = buff;
		if ((r <= 0) || (r < BUFFER_SIZE && ft_strchr(save[fd], '\n') == -1))
			return (ft_strdup(&save[fd]));
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line = %s", line);
		free(line);
	}
}
	while (a)
	{
		line = get_next_line(fd);
		printf("testdefoufurieux = %s", line);
		if (line == NULL)
			a = 0;
		free(line);
	}
	free(line);
	return (0);
}
*/
