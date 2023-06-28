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
	//gettimeofday(&philo_thread->start_philo, NULL);
	printf("timer_start = %lld\n", philo_thread->timer.timer_start);
	while (4)
	{
		gettimeofday(&philo_thread->timer.inwhile, NULL);
		//gettimeofday(&philo_thread->inwhile_philo, NULL);
		//print_timer(philo_thread);
		//printf("Philosopher %d thinking\n", philo_thread->index);
		//while (time_before_eat(philo_thread) <= philo_thread->time_eat);
	}
	return (NULL);
}

void	create_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->value.nb_philo)
	{
		pthread_mutex_init(&philo[i].fork, NULL);
		pthread_create(&philo[i].thread_id, NULL, start_thread, &philo[i]);
		i++;
	}
}

void	manage_thread(t_philo *philo)
{
	gettimeofday(&philo->timer.start, NULL);
	philo->timer.timer_start = (philo->timer.start.tv_sec * 1000) +
		(philo->timer.start.tv_usec / 1000);
	printf("timer_start = %lld\n", philo->timer.timer_start);
	create_thread(philo);
	while (4);
		//gettimeofday(&philo->timer.inwhile, NULL);
		//print_timer(philo);
}
