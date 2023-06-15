#include "philo.h"

void	manage_thread(t_philo *philo)
{
	int	i;

	i = 0;

	while (i < philo->value.nb_philo - 1)
	{
		pthread_mutex_initi(&philo[i].fork, NULL);
		pthread_create(&philo[i].thread_id, start_thread, philo);
		i++;
	}
}
