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
	(void) philo_thread;
	printf("thread_id = %ld\n", (philo_thread->thread_id));
	return (NULL);
}

void	manage_thread(t_philo *philo)
{
	int				i;
	struct timeval	start;
	struct timeval	inwhile;

	i = 0;
	gettimeofday(&start, NULL);
	while (i < philo->value.nb_philo)
	{
		pthread_mutex_init(&philo[i].fork, NULL);
		pthread_create(&philo[i].thread_id, NULL, start_thread, &philo[i]);
		i++;
	}
	pthread_mutex_unlock(&philo->value.synchro);
	while (1)
	{
		gettimeofday(&inwhile, NULL);
		printf("time = %ld\n", ((inwhile.tv_sec - start.tv_sec) * 1000) +
			((inwhile.tv_usec - start.tv_usec) / 1000));
	}
}
