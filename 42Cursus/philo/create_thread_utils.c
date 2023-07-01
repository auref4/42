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

int	ft_strcmp(const char *first, const char *second)
{
	size_t			i;
	unsigned char	*ufirst;
	unsigned char	*usecond;

	i = 0;
	ufirst = (unsigned char *)first;
	usecond = (unsigned char *)second;
	while (ufirst[i] && usecond[i] && ufirst[i] == usecond[i])
		i++;
	return (ufirst[i] - usecond[i]);
}

int	is_dead(t_philo *philo_thread)
{
	if (*philo_thread->value.is_dead > 0)
		return (1);
	return (0);
}

void	print(t_philo *philo_thread, char *str)
{
	if (*philo_thread->value.philo_eated == 0)
	{
		pthread_mutex_lock(&philo_thread->value.print);
		gettimeofday(&philo_thread->value.inwhile, NULL);
		printf("%ld %d %s", ((philo_thread->value.inwhile.tv_sec * 1000) + \
			(philo_thread->value.inwhile.tv_usec / 1000) - \
			philo_thread->value.timer_start), philo_thread->index, str);
		pthread_mutex_unlock(&philo_thread->value.print);
	}
	else if (*philo_thread->value.philo_eated > 0 && ft_strcmp(str, "died\n") == 0)
	{
		pthread_mutex_lock(&philo_thread->value.print);
		gettimeofday(&philo_thread->value.inwhile, NULL);
		printf("%ld %d %s", ((philo_thread->value.inwhile.tv_sec * 1000) + \
			(philo_thread->value.inwhile.tv_usec / 1000) - \
			philo_thread->value.timer_start), philo_thread->index, str);
		pthread_mutex_unlock(&philo_thread->value.print);
	}
}
