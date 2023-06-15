#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <limits.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct	s_value {
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_meal;
}				t_value;

typedef struct	s_philo {
	int						index;
	pthread_mutex_t			fork;
	pthread_t				thread_id;
	t_value					value;
}				t_philo;

void	error(int nb);
int		check_arg(char **argv);
int		philo(int argc, char **argv);
int		init_value(int argc, char **argv, t_value *value);
void	init_philo(t_philo *philo, t_value value);
int		ft_atoi(const char *s, int *nb);

# endif
