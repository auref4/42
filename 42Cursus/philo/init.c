/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:03:20 by auferran          #+#    #+#             */
/*   Updated: 2023/07/01 01:07:54 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo, t_value value)
{
	int	i;

	i = 0;
	while (i < value.nb_philo)
	{
		philo[i].index = i + 1;
		philo[i].thread_id = 0;
		philo[i].value = value;
		philo[i].start_p = 0;
		philo[i].last_m = 0;
		philo[i].i = 0;
		i++;
	}
}

int	init_value(int argc, char **argv, t_value *value)
{
	if (!ft_atoi(argv[1], &value->nb_philo))
		return (0);
	if (!ft_atoi(argv[2], &value->time_die))
		return (0);
	if (!ft_atoi(argv[3], &value->time_eat))
		return (0);
	if (!ft_atoi(argv[4], &value->time_sleep))
		return (0);
	if (argc == 6)
	{
		if (!ft_atoi(argv[5], &value->nb_meal))
			return (0);
		if (value->nb_meal < 1)
			return (error(1), 0);
	}
	else
		value->nb_meal = -1;
	if (value->nb_philo < 1 || value->time_die < 1 || value->time_eat < 1
		|| value->time_sleep < 1)
		return (error(1), 0);
	return (1);
}
