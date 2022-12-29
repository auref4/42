/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:25:07 by auferran          #+#    #+#             */
/*   Updated: 2022/12/17 19:29:41 by auferran         ###   ########.fr       */
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
	while (4)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		r = read(fd, buff, BUFFER_SIZE);
		buff[r] = '\0';
		n = ft_strchr(buff, '\n');
		if (save)
			buff = ft_strjoin(save, buff);
		if (n > 0)
		{
			line = ft_substr(buff, 0, n);
			save = ft_substr(&buff[n + 1], 0, ft_strlen(&buff[n + 1])); 
			free(buff);
			return (line);
		}
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
}

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
		printf("%s", line);
		free (line);
	}
	return (0);
}
