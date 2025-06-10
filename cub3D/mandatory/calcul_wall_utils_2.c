/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_wall_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <madaguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:35:20 by auferran          #+#    #+#             */
/*   Updated: 2024/01/30 02:12:21 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	size_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

double	calcul_projection_plane(void)
{
	double	nb;
	double	angle;
	double	t;

	angle = (((POV / 2) * M_PI) / 180);
	t = tan(angle);
	nb = (WIDTH / 2) / t;
	return (nb);
}

void	remove_fishbowl(double *distance, double i)
{
	double	c;
	double	tmp;
	double	angle;

	angle = ((i * M_PI) / 180);
	c = cos(angle);
	tmp = *distance;
	*distance = tmp * c;
}
