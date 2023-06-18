#include "philo.h"

void	start_thread(t_philo *philo)
{

}

void	manage_thread(t_philo *philo)
{
	int	i;

	i = 0;

	while (i < philo->value.nb_philo)
	{
		pthread_mutex_init(&philo[i].fork, NULL);
		pthread_create(&philo[i].thread_id, start_thread, philo);
		i++;
	}
}
