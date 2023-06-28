#include "philo.h"

void	print_timer(t_philo *philo_thread)
{
	printf("time = %lld ", ((philo_thread->timer.inwhile.tv_sec * 1000) + (philo_thread->timer.inwhile.tv_usec / 1000) + philo_thread->timer.timer_start));
}
