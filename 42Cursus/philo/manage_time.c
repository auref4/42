/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:47:10 by auferran          #+#    #+#             */
/*   Updated: 2023/07/07 21:22:39 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timer_last_meal(t_philo *philo_thread)
{
	pthread_mutex_lock(&philo_thread->mutex->timer);
	gettimeofday(&philo_thread->last_meal, NULL);
		philo_thread->last_m = (philo_thread->last_meal.tv_sec * 1000) + \
		(philo_thread->last_meal.tv_usec / 1000);
	pthread_mutex_unlock(&philo_thread->mutex->timer);
}

void	timer_start_philo(t_philo *philo_thread)
{
	pthread_mutex_lock(&philo_thread->mutex->timer);
	gettimeofday(&philo_thread->start_philo, NULL);
		philo_thread->start_p = (philo_thread->start_philo.tv_sec * 1000) + \
		(philo_thread->start_philo.tv_usec / 1000);
	pthread_mutex_unlock(&philo_thread->mutex->timer);
}
