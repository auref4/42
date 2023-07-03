/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 05:02:04 by auferran          #+#    #+#             */
/*   Updated: 2023/07/01 05:24:27 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	meal_eated(t_philo *philo_thread)
{
	philo_thread->meal_eated++;
	pthread_mutex_lock(&philo_thread->mutex.protect);
	if (philo_thread->meal_eated == philo_thread->value.nb_meal)
		(*philo_thread->value.philo_eated)++;
	usleep(200);
	pthread_mutex_unlock(&philo_thread->mutex.protect);
}

void	eating(t_philo *philo_thread)
{
	if (philo_thread->index % 2 == 0)
	{
		lock_modulo_2(philo_thread);
		timer_last_meal(philo_thread);
		print(philo_thread, "is eating\n");
		usleep(philo_thread->value.time_eat * 1000);
		unlock_modulo_2(philo_thread);
	}
	else
	{
		lock(philo_thread);
		timer_last_meal(philo_thread);
		print(philo_thread, "is eating\n");
		usleep(philo_thread->value.time_eat * 1000);
		unlock(philo_thread);
	}
}

void	*start_thread(void *philo)
{
	t_philo	*philo_thread;

	philo_thread = (t_philo *)philo;
	philo_thread->meal_eated = 0;
	timer_start_philo(philo_thread);
	while (4)
	{
		if (philo_thread->index % 2)
			usleep(3000);
		print(philo_thread, "is thinking\n");
		usleep(200);
		eating(philo_thread);
		meal_eated(philo_thread);
		print(philo_thread, "is sleeping\n");
		usleep(philo_thread->value.time_sleep * 1000);
		if (is_dead(philo_thread))
			break ;
	}
	return (NULL);
}

void	print(t_philo *philo_thread, char *str)
{
	pthread_mutex_lock(&philo_thread->mutex.print);
	if (*philo_thread->value.is_dead == 0)
	{
		gettimeofday(&philo_thread->value.inwhile, NULL);
		printf("%ld %d %s", ((philo_thread->value.inwhile.tv_sec * 1000) + \
			(philo_thread->value.inwhile.tv_usec / 1000) - \
			philo_thread->value.timer_start), philo_thread->index, str);
	}
	else if (*philo_thread->value.is_dead > 0 && !ft_strcmp(str, "died\n"))
	{
		gettimeofday(&philo_thread->value.inwhile, NULL);
		printf("%ld %d %s", ((philo_thread->value.inwhile.tv_sec * 1000) + \
			(philo_thread->value.inwhile.tv_usec / 1000) - \
			philo_thread->value.timer_start), philo_thread->index, str);
	}
	pthread_mutex_unlock(&philo_thread->mutex.print);
}
