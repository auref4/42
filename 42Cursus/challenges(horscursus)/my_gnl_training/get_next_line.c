#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	search_n(char *save, int *n)
{
	int		i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
		{
			*n = i;
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*line_on_save(char **save, int n)
{
	int		i;
	int		j;
	int		len;
	char	*line;
	char	*tmp;

	i = 0;
	line = malloc(sizeof(char) * (n + 2));
	if (!line)
		return (NULL);
	while ((*save)[i] != '\n')
	{
		line[i] = (*save)[i];
		i++;
	}
	line[i] = '\n';
	i++;
	line[i] = 0;
	if (!save[i])
	{
		free(*save);
		*save = NULL;
		return (line);
	}
	len = ft_strlen(*save) - i;
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	while ((*save)[i])
	{
		tmp[j] = (*save)[i];
		j++;
		i++;
	}
	tmp[j] = 0;
	free(*save);
	*save = tmp;
	return (line);
}

int	verif_read(int *r,  int fd, char **buffer, char *save)
{
	*r = read(fd, *buffer, BUFFER_SIZE);
	if (*r <= 0 && !save)
		return (0);
	return (1);
}

int	update_save(char **save, char *buffer)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(*save) + ft_strlen(buffer) + 1));
	if (!tmp)
		return (0);
	while ((*save)[i])
	{
		tmp[i] = (*save)[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		tmp[i] = buffer[j];
		i++;
		j++;
	}
	tmp[i] = 0;
	free(*save);
	*save = tmp;
	return (1);
}

char	*ft_strcpy(char *buffer)
{
	int		i;
	char	*save;

	i = 0;
	save = malloc(sizeof(char) * ft_strlen(buffer) + 1);
	if (!save)
		return (NULL);
	while (buffer[i])
	{
		save[i] = buffer[i];
		i++;
	}
	save[i] = 0;
	return (save);
}

char	*get_next_line(int fd)
{
	int			r;
	int			n;
	static char	*save;
	char		*buffer;

	n = -1;
	r = 0;
	while (1)
	{
		if (BUFFER_SIZE <= 0)
			break ;
		if (save)
		{
			if (search_n(save, &n) != -1)
				return (line_on_save(&save, n));
		}
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		if (!verif_read(&r, fd, &buffer, save))
			return (free(buffer), NULL);
		if (r <= 0 && save)
			return (free(buffer) , save);
		if (!save)
		{
			save = ft_strcpy(buffer);
			if (!save)
				return (free(buffer), NULL);
		}
		else if (!update_save(&save, buffer))
			return (free(buffer), NULL);
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line = %s", line);
		free(line);
	}
}
