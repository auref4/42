/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <madaguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:17:07 by madaguen          #+#    #+#             */
/*   Updated: 2024/01/31 01:38:48 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include <stdio.h>

void	set_case(int *ptr, int color, int size_line)
{
	int	i;
	int	j;

	i = 0;
	while (i < M_SIZE)
	{
		j = 0;
		while (j < M_SIZE)
		{
			ptr[j] = color;
			j++;
		}
		i++;
		ptr += (size_line);
	}
}

void	draw_minimap(t_minimap m, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == '1')
				set_case(m.map + ptr_offset(i, j, m.width, M_SIZE), W, m.width);
			else if (map[i][j] == 'd')
				set_case(m.map + ptr_offset(i, j, m.width, M_SIZE), D, m.width);
			else
				set_case(m.map + ptr_offset(i, j, m.width, M_SIZE), G, m.width);
			j++;
		}
		i++;
	}
}

void	get_height_width(char **map, int *width, int *height)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (j > *width)
			*width = j;
		i++;
	}
	*height = i;
}

void	init_minimap_data(t_minimap *mini, char **map)
{
	get_height_width(map, &mini->width, &mini->height);
	mini->height *= M_SIZE;
	mini->width *= M_SIZE;
	mini->height_img = HEIGHT_MAP * M_SIZE;
	mini->width_img = WIDTH_MAP * M_SIZE;
	if (mini->width < mini->width_img)
		mini->width_img = mini->width;
	if (mini->height < mini->height_img)
		mini->height_img = mini->height;
	mini->radius = mini->height_img;
	if (mini->radius > mini->width_img)
		mini->radius = mini->width_img;
	mini->width_img = mini->radius;
	mini->width_img = mini->radius;
	mini->radius /= 2;
}

int	create_minimap(t_minimap *mini, char **map)
{
	int	i;
	int	size;

	init_minimap_data(mini, map);
	mini->map = malloc(mini->width * mini->height * sizeof(int));
	if (!mini->map)
		return (0);
	mini->img = malloc(mini->width_img * mini->height_img * sizeof(int));
	if (!mini->img)
		return (0);
	i = 0;
	size = mini->width * mini->height;
	while (i < size)
		mini->map[i++] = 0;
	draw_minimap(*mini, map);
	return (1);
}
