#include "philo.h"

int	philo(int argc, char **argv)
{
	t_value	value;
	t_philo	*philo;

	if(!init_value(argc, argv, &value))
		return (0);
	philo = malloc(sizeof(t_philo) * value.nb_philo);
	if (!philo)
		return (0);
	init_philo(philo, value);
	manage_thread(philo);
	//free(philo);
	return (1);
}
