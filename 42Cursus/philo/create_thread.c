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

int	checker_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->value.nb_philo)
	{
		if (philo[i].i == 0 && philo[i].start_p > 0)
		{
			if (death_timer_1(&philo[i]))
			{
				print(&philo[i], "died\n");
				return (1);
			}
		}
		if (philo[i].i == 1 && philo[i].last_m > 0)
		{
			if (death_timer_2(&philo[i]))
			{
				print(&philo[i], "died\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	eating(t_philo *philo_thread)
{
	if (philo_thread->index % 2 == 0)
	{
		lock_modulo_2(philo_thread);
		print(philo_thread, "is eating\n");
		usleep(philo_thread->value.time_eat * 1000);
		unlock_modulo_2(philo_thread);
	}
	else
	{
		lock(philo_thread);
		print(philo_thread, "is eating\n");
		usleep(philo_thread->value.time_eat * 1000);
		unlock(philo_thread);
	}
}

void	*start_thread(void *philo)
{
	t_philo	*philo_thread;

	philo_thread = (t_philo *)philo;
	philo_thread->i = 0;
	philo_thread->meal_eated = 0;
	while (4)
	{
		timer_start_philo(philo_thread);
		print(philo_thread, "is thinking\n");
		eating(philo_thread);
		timer_last_meal(philo_thread);
		philo_thread->meal_eated++;
		if (philo_thread->meal_eated == philo_thread->value.nb_meal)
		{
			pthread_mutex_lock(&philo_thread->value.protect);
			(*philo_thread->value.philo_eated)++;
			pthread_mutex_unlock(&philo_thread->value.protect);
		}
		print(philo_thread, "is sleeping\n");
		usleep(philo_thread->value.time_sleep);
		if (is_dead(philo_thread))
			break ;
	}
	return (NULL);
}

void	create_thread(t_philo *philo, t_value value)
{
	int	i;

	i = 0;
	pthread_mutex_init(&value.print, NULL);
	gettimeofday(&value.start, NULL);
	value.timer_start = (value.start.tv_sec * 1000) + \
		(value.start.tv_usec / 1000);
	while (i < philo->value.nb_philo)
	{
		philo[i].value = value;
		pthread_mutex_init(&philo[i].fork, NULL);
		pthread_create(&philo[i].thread_id, NULL, start_thread, &philo[i]);
		philo[i].start_p = 0;
		philo[i].last_m = 0;
		i++;
	}
	while (4)
	{
		if (*value.philo_eated == value.nb_philo)
			break ;
		if (checker_death(philo))
			break ;
	}
	(*value.is_dead)++;
	waiting_close_thread(philo);

}
