#include "philo.h"

void	unlock_modulo_2(t_philo *philo_thread)
{
	int	i;

	i = 1 - philo_thread->value.nb_philo;
	pthread_mutex_unlock(&philo_thread->fork);
	print_timer(philo_thread);
	printf("Philosopher %d put down fork %d\n", philo_thread->index,
		philo_thread->index);
	pthread_mutex_unlock(&philo_thread->value.print);
	if (philo_thread->index == philo_thread->value.nb_philo)
	{
		pthread_mutex_unlock(&philo_thread[i].fork);
		print_timer(philo_thread);
		printf("Philosopher %d put down fork %d\n", philo_thread->index,
			philo_thread[i].index);
		pthread_mutex_unlock(&philo_thread->value.print);
	}
	else
	{
		pthread_mutex_unlock(&philo_thread[1].fork);
		print_timer(philo_thread);
		printf("Philosopher %d put down fork %d\n", philo_thread->index,
			philo_thread[1].index);
		pthread_mutex_unlock(&philo_thread->value.print);
	}
}

void	lock_modulo_2(t_philo *philo_thread)
{
	int	i;

	i = 1 - philo_thread->value.nb_philo;
	pthread_mutex_lock(&philo_thread->fork);
	print_timer(philo_thread);
	printf("Philosopher %d taking fork %d\n", philo_thread->index,
		philo_thread->index);
	pthread_mutex_unlock(&philo_thread->value.print);
	if (philo_thread->index == philo_thread->value.nb_philo)
	{
		pthread_mutex_lock(&philo_thread[i].fork);
		print_timer(philo_thread);
		printf("Philosopher %d taking fork %d\n", philo_thread->index,
			philo_thread[i].index);
		pthread_mutex_unlock(&philo_thread->value.print);
	}
	else
	{
		pthread_mutex_lock(&philo_thread[1].fork);
		print_timer(philo_thread);
		printf("Philosopher %d taking fork %d\n", philo_thread->index,
			philo_thread[1].index);
		pthread_mutex_unlock(&philo_thread->value.print);
	}
	if (philo_thread->i == 0)
		philo_thread->i++;
}

void	unlock(t_philo *philo_thread)
{
	int	i;

	i = 1 - philo_thread->value.nb_philo;
	if (philo_thread->index == philo_thread->value.nb_philo)
	{
		pthread_mutex_unlock(&philo_thread[i].fork);
		print_timer(philo_thread);
		printf("Philosopher %d put down fork %d\n", philo_thread->index,
			philo_thread[i].index);
		pthread_mutex_unlock(&philo_thread->value.print);
	}
	else
	{
		pthread_mutex_unlock(&philo_thread[1].fork);
		print_timer(philo_thread);
		printf("Philosopher %d put down fork %d\n", philo_thread->index,
			philo_thread[1].index);
		pthread_mutex_unlock(&philo_thread->value.print);
	}
	pthread_mutex_unlock(&philo_thread->fork);
	print_timer(philo_thread);
	printf("Philosopher %d put down fork %d\n", philo_thread->index,
		philo_thread->index);
	pthread_mutex_unlock(&philo_thread->value.print);
}

void	lock(t_philo *philo_thread)
{
	int	i;

	i = 1 - philo_thread->value.nb_philo;
	if (philo_thread->index == philo_thread->value.nb_philo)
	{
		pthread_mutex_lock(&philo_thread[i].fork);
		print_timer(philo_thread);
		printf("Philosopher %d taking fork %d\n", philo_thread->index,
			philo_thread[i].index);
		pthread_mutex_unlock(&philo_thread->value.print);
	}
	else
	{
		pthread_mutex_lock(&philo_thread[1].fork);
		print_timer(philo_thread);
		printf("Philosopher %d taking fork %d\n", philo_thread->index,
			philo_thread[1].index);
		pthread_mutex_unlock(&philo_thread->value.print);
	}
	pthread_mutex_lock(&philo_thread->fork);
	print_timer(philo_thread);
	printf("Philosopher %d taking fork %d\n", philo_thread->index,
		philo_thread->index);
	pthread_mutex_unlock(&philo_thread->value.print);
	if (philo_thread->i == 0)
		philo_thread->i++;
}
