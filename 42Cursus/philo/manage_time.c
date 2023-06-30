#include "philo.h"

int	death_timer_2(t_philo *philo)
{
	long int	time;
	gettimeofday(&philo->inwhile_death, NULL);
		time = (philo->inwhile_death.tv_sec * 1000) +
		(philo->inwhile_death.tv_usec / 1000);
	if (time - (philo->last_meal.tv_sec * 1000) +
		(philo->last_meal.tv_usec / 1000)
			>= philo->value.time_die)
		return (1);
	return (0);
}

int	death_timer_1(t_philo *philo)
{
	long int	time;
	gettimeofday(&philo->inwhile_death, NULL);
		time = (philo->inwhile_death.tv_sec * 1000) +
		(philo->inwhile_death.tv_usec / 1000);
	if (time - (philo->start_philo.tv_sec * 1000) +
		(philo->start_philo.tv_usec / 1000)
			>= philo->value.time_die)
		return (1);
	return (0);

}

int	sleeping_timer(t_philo *philo_thread)
{
	long int	time;

	gettimeofday(&philo_thread->inwhile_sleeping, NULL);
	time = (philo_thread->inwhile_sleeping.tv_sec * 1000) +
		(philo_thread->inwhile_sleeping.tv_usec / 1000);
	if (time - (philo_thread->sleeping.tv_sec * 1000) +
		(philo_thread->sleeping.tv_usec / 1000)
			>= philo_thread->value.time_sleep)
		return (1);
	return (0);
}

int	eating_timer(t_philo *philo_thread)
{
	long int	time;

	gettimeofday(&philo_thread->inwhile_eating, NULL);
	time = (philo_thread->inwhile_eating.tv_sec * 1000) +
		(philo_thread->inwhile_eating.tv_usec / 1000);
	if (time - (philo_thread->eating.tv_sec * 1000) +
		(philo_thread->eating.tv_usec / 1000)
			>= philo_thread->value.time_eat)
		return (1);
	return (0);
}

void	print_timer(t_philo *philo_thread)
{
	pthread_mutex_lock(&philo_thread->value.print);
	gettimeofday(&philo_thread->value.inwhile, NULL);
	printf("time = %ld ", ((philo_thread->value.inwhile.tv_sec * 1000) +
		(philo_thread->value.inwhile.tv_usec / 1000) -
			philo_thread->value.timer_start));
}
