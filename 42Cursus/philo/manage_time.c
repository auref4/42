#include "philo.h"

void	print_timer(t_philo *philo_thread)
{
	printf("time = %ld ", ((philo_thread->value.inwhile.tv_sec * 1000) +
		(philo_thread->value.inwhile.tv_usec / 1000) -
			philo_thread->value.timer_start));
}
