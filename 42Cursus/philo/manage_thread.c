#include "philo.h"

void	*start_thread(void *philo)
{
	t_philo	*philo_thread;

	philo_thread = (t_philo *)philo;
	printf("avant mutex\n");
	pthread_mutex_lock(&philo_thread->value.synchro);
	printf("thread_id = %ld\n", (philo_thread->thread_id));
	return (NULL);
}

void	manage_thread(t_philo *philo)
{
	int	i;
	timeval	start;

	i = 0;
	pthread_mutex_init(&philo->value.synchro, NULL);
	while (i < philo->value.nb_philo)
	{
		pthread_mutex_init(&philo[i].fork, NULL);
		pthread_create(&philo[i].thread_id, NULL, start_thread, &philo[i]);
		i++;
	}
	pthread_mutex_unlock(&philo->value.synchro);
	while (1);
}
