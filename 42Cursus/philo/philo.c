/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:03:29 by auferran          #+#    #+#             */
/*   Updated: 2023/06/23 19:06:13 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(int argc, char **argv)
{
	t_value	value;
	t_philo	*philo;

	if (!init_value(argc, argv, &value))
		return (0);
	philo = malloc(sizeof(t_philo) * value.nb_philo);
	if (!philo)
		return (0);
	init_philo(philo, value);
	create_thread(philo, value);
	free(philo);
	return (1);
}
