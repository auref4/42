/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <madaguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 02:13:35 by madaguen          #+#    #+#             */
/*   Updated: 2024/01/31 01:22:06 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handdle_space(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (ft_isspace(map[j][i]))
				map[j][i] = '1';
			i++;
		}
		j++;
	}
}

int	floodfill(int x, int y, char **map)
{
	if (y < 0 || y > size_map(map) || x < 0 \
	|| x > ft_strlen(map[y]) || map[y][x] == ' ')
		return (write(2, "unclosed map\n", 14), 0);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (1);
	if (map[y][x] == '0')
		map[y][x] = 'F';
	else if (map[y][x] == 'D')
		map[y][x] = 'd';
	if (!floodfill(x + 1, y, map))
		return (0);
	if (!floodfill(x - 1, y, map))
		return (0);
	if (!floodfill(x, y + 1, map))
		return (0);
	if (!floodfill(x, y - 1, map))
		return (0);
	return (1);
}

int	check_map(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			if (map->map[j][i] == '0')
			{
				if (!floodfill(i, j, map->map))
					return (0);
			}
			i++;
		}
		j++;
	}
	handdle_space(map->map);
	return (1);
}
