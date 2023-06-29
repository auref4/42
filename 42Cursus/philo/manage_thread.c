/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:03:26 by auferran          #+#    #+#             */
/*   Updated: 2023/06/23 19:06:02 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_thread(void *philo)
{
	t_philo	*philo_thread;

	philo_thread = (t_philo *)philo;
	while (4)
	{
	 	gettimeofday(&philo_thread->value.inwhile, NULL);
		print_timer(philo_thread);
		printf("Philosopher %d thinking\n", philo_thread->index);
		while(4);
		//while (time_before_eat(philo_thread) <= philo_thread->time_eat);
	}
	return (NULL);
}

void	create_thread(t_philo *philo, t_value value)
{
	int	i;

	i = 0;
	while (i < philo->value.nb_philo)
	{
		philo[i].value = value;
		pthread_mutex_init(&philo[i].fork, NULL);
		pthread_create(&philo[i].thread_id, NULL, start_thread, &philo[i]);
		i++;
	}
}

void	manage_thread(t_philo *philo, t_value value)
{
	gettimeofday(&value.start, NULL);
	value.timer_start = (value.start.tv_sec * 1000) +
		(value.start.tv_usec / 1000);
	create_thread(philo, value);
	while (4);
}
