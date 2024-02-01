/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <madaguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:17:57 by madaguen          #+#    #+#             */
/*   Updated: 2024/01/31 01:21:52 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	handdle_space(char **map, t_env *env)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'd')
				env->map.nb_door++;
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
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'd')
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

int	check_map(t_map *map, t_env *env)
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
	handdle_space(map->map, env);
	return (1);
}
