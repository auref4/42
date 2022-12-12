/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:25:07 by auferran          #+#    #+#             */
/*   Updated: 2022/12/12 21:40:24 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	int			i;
	int			read;

	i = 0;
	line = NULL;
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (4)
	{
		read = read(fd, save, BUFFER_SIZE);

	}

}

int	main(void)
{
	get_next_line(5);
}
