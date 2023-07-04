/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:03:26 by auferran          #+#    #+#             */
/*   Updated: 2023/07/01 05:15:24 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_philo *philo, t_mutex *mutex, int index)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&mutex->print);
	pthread_mutex_destroy(&mutex->protect);
	while (i < index)
	{
		pthread_mutex_destroy(&philo[i].fork);
		i++;
	}
}

void	waiting_close_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->value.nb_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
}

void	infinit_while(t_philo *philo, t_value value, t_mutex mutex)
{
	while (4)
	{
		pthread_mutex_lock(&mutex.protect);
		if (*value.philo_eated == value.nb_philo || checker_death(philo))
			break ;
		pthread_mutex_unlock(&mutex.protect);
		usleep(200);
	}
	(*value.is_dead)++;
	pthread_mutex_unlock(&mutex.protect);
}

int	create_thread(t_philo *philo, t_value *value, t_mutex *mutex)
{
	int	i;

	i = 0;
	while (i < philo->value.nb_philo)
	{
		philo[i].value = *value;
		philo[i].mutex = *mutex;
		if (pthread_mutex_init(&philo[i].fork, NULL) != 0)
		{
			pthread_mutex_lock(&mutex->print);
			(*value->is_dead)++;
			pthread_mutex_unlock(&mutex->print);
			waiting_close_thread(philo);
			destroy_mutex(philo, mutex, i);
			return (0);
		}
		pthread_create(&philo[i].thread_id, NULL, start_thread, &philo[i]);
		i++;
	}
	return (1);
}

void	philosophers(t_philo *philo, t_value value, t_mutex mutex)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&mutex.print, NULL) != 0)
		return ;
	if (pthread_mutex_init(&mutex.protect, NULL) != 0)
		return ;
	gettimeofday(&value.start, NULL);
	value.timer_start = (value.start.tv_sec * 1000) + \
		(value.start.tv_usec / 1000);
	if (!create_thread(philo, &value, &mutex))
		return ;
	infinit_while(philo, value, mutex);
	waiting_close_thread(philo);
	destroy_mutex(philo, &mutex, i);
}
