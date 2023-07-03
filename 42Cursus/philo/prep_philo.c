/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:03:29 by auferran          #+#    #+#             */
/*   Updated: 2023/07/01 05:00:27 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	prep_philo(int argc, char **argv)
{
	int		n;
	int		n2;
	t_value	value;
	t_mutex	mutex;
	t_philo	*philo;

	value.philo_eated = &n;
	value.is_dead = &n2;
	*value.philo_eated = 0;
	*value.is_dead = 0;
	if (!init_value(argc, argv, &value))
		return (0);
	philo = malloc(sizeof(t_philo) * value.nb_philo);
	if (!philo)
		return (0);
	init_philo(philo, value);
	philosophers(philo, value, mutex);
	free(philo);
	return (1);
}
