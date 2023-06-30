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

int	checker_death(t_philo *philo)
{
	int	i;

	i = 0;
	while(i < philo[i].value.nb_philo)
	{
		if (philo[i].i == 0)
		{
			if (death_timer_1(philo))
				return (1);
		}
		else
			if (death_timer_2(philo))
				return (1);
		i++;
	}
	return (0);
}

void	im_sleeping(t_philo *philo_thread)
{
	print_timer(philo_thread);
	printf("Philosopher %d im sleeping\n", philo_thread->index);
	pthread_mutex_unlock(&philo_thread->value.print);
	gettimeofday(&philo_thread->sleeping, NULL);
	while (4)
	{
		if (sleeping_timer(philo_thread))
			break;
	}
	print_timer(philo_thread);
	printf("Philosopher %d i wake up\n", philo_thread->index);
	pthread_mutex_unlock(&philo_thread->value.print);
}

void	im_hungry(t_philo *philo_thread)
{
	print_timer(philo_thread);
	printf("Philosopher %d im hungry\n", philo_thread->index);
	pthread_mutex_unlock(&philo_thread->value.print);
	if (philo_thread->index % 2 == 0)
	{
		lock_modulo_2(philo_thread);
		gettimeofday(&philo_thread->eating, NULL);
		while (4)
		{
			if (eating_timer(philo_thread))
				break;
		}
		unlock_modulo_2(philo_thread);
	}
	else
	{
		lock(philo_thread);
		gettimeofday(&philo_thread->eating, NULL);
		while (4)
		{
			if (eating_timer(philo_thread))
				break;
		}
		unlock(philo_thread);
	}
}

void	*start_thread(void *philo)
{
	t_philo	*philo_thread;

	philo_thread = (t_philo *)philo;
	philo_thread->i = 0;
	while (4)
	{
		gettimeofday(&philo_thread->start_philo, NULL);
		print_timer(philo_thread);
		printf("Philosopher %d thinking\n", philo_thread->index);
		pthread_mutex_unlock(&philo_thread->value.print);
		im_hungry(philo_thread);
		gettimeofday(&philo_thread->last_meal, NULL);
		im_sleeping(philo_thread);
		while (4);
	}
	return (NULL);
}

void	create_thread(t_philo *philo, t_value value)
{
	int	i;

	i = 0;
	pthread_mutex_init(&value.print, NULL);
	gettimeofday(&value.start, NULL);
	value.timer_start = (value.start.tv_sec * 1000) +
		(value.start.tv_usec / 1000);
	while (i < philo->value.nb_philo)
	{
		philo[i].value = value;
		pthread_mutex_init(&philo[i].fork, NULL);
		pthread_create(&philo[i].thread_id, NULL, start_thread, &philo[i]);
		i++;
	}
	while (4)
	{
		if (checker_death(philo))
			break ;
	}
}
