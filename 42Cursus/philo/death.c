#include "philo.h"

int	death_timer_2(t_philo *philo)
{
	long int	time;

	gettimeofday(&philo->inwhile_death, NULL);
	time = (philo->inwhile_death.tv_sec * 1000) + \
		(philo->inwhile_death.tv_usec / 1000);
	if ((time - philo->last_m) > philo->value.time_die)
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

int	is_dead(t_philo *philo_thread)
{
	if (*philo_thread->value.is_dead > 0)
		return (1);
	return (0);
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
