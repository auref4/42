/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_unlock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:47:01 by auferran          #+#    #+#             */
/*   Updated: 2023/07/09 17:01:41 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlock_modulo_2(t_philo *philo_thread)
{
	int	i;

	i = 1 - philo_thread->value->nb_philo;
	pthread_mutex_unlock(&philo_thread->fork);
	usleep(50);
	if (philo_thread->index == philo_thread->value->nb_philo)
		pthread_mutex_unlock(&philo_thread[i].fork);
	else
		pthread_mutex_unlock(&philo_thread[1].fork);
}

int	lock_modulo_2(t_philo *philo_thread)
{
	int	i;

	i = 1 - philo_thread->value->nb_philo;
	pthread_mutex_lock(&philo_thread->fork);
	print(philo_thread, "has taken a fork\n");
	if (philo_thread->value->nb_philo == 1)
	{
		pthread_mutex_unlock(&philo_thread->fork);
		usleep(philo_thread->value->time_die * 1000);
		return (0);
	}
	if (philo_thread->index == philo_thread->value->nb_philo)
	{
		pthread_mutex_lock(&philo_thread[i].fork);
		print(philo_thread, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(&philo_thread[1].fork);
		print(philo_thread, "has taken a fork\n");
	}
	return (1);
}

void	unlock(t_philo *philo_thread)
{
	int	i;

	i = 1 - philo_thread->value->nb_philo;
	if (philo_thread->index == philo_thread->value->nb_philo)
		pthread_mutex_unlock(&philo_thread[i].fork);
	else
		pthread_mutex_unlock(&philo_thread[1].fork);
	usleep(50);
	pthread_mutex_unlock(&philo_thread->fork);
}

int	lock(t_philo *philo_thread)
{
	int	i;

	i = 1 - philo_thread->value->nb_philo;
	if (philo_thread->index == philo_thread->value->nb_philo)
	{
		pthread_mutex_lock(&philo_thread[i].fork);
		print(philo_thread, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(&philo_thread[1].fork);
		print(philo_thread, "has taken a fork\n");
	}
	if (philo_thread->value->nb_philo == 1)
	{
		if (philo_thread->index == philo_thread->value->nb_philo)
			pthread_mutex_unlock(&philo_thread[i].fork);
		else
			pthread_mutex_unlock(&philo_thread[1].fork);
		usleep(philo_thread->value->time_die * 1000);
		return (0);
	}
	pthread_mutex_lock(&philo_thread->fork);
	print(philo_thread, "has taken a fork\n");
	return (1);
}
