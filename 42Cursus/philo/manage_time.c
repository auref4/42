/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:47:10 by auferran          #+#    #+#             */
/*   Updated: 2023/07/01 05:20:42 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_timer_2(t_philo *philo)
{
	long int	time;

	gettimeofday(&philo->inwhile_death, NULL);
	time = (philo->inwhile_death.tv_sec * 1000) + \
		(philo->inwhile_death.tv_usec / 1000);
	if (time - philo->last_m > philo->value.time_die)
		return (1);
	return (0);
}

int	death_timer_1(t_philo *philo)
{
	long int	time;

	gettimeofday(&philo->inwhile_death, NULL);
	time = (philo->inwhile_death.tv_sec * 1000) + \
		(philo->inwhile_death.tv_usec / 1000);
	if (time - philo->start_p > philo->value.time_die)
		return (1);
	return (0);

}

void	timer_last_meal(t_philo *philo_thread)
{
	gettimeofday(&philo_thread->last_meal, NULL);
		philo_thread->last_m = (philo_thread->last_meal.tv_sec * 1000) + \
		(philo_thread->last_meal.tv_usec / 1000);
}

void	timer_start_philo(t_philo *philo_thread)
{
	gettimeofday(&philo_thread->start_philo, NULL);
		philo_thread->start_p = (philo_thread->start_philo.tv_sec * 1000) + \
		(philo_thread->start_philo.tv_usec / 1000);
}
