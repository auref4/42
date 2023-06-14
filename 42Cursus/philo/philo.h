#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <limits.h>
#include <pthread.h>

typedef struct	s_value {
	int		nb_of_p;
	int		nb_of_f;
	int		t_to_d;
	int		t_to_e;
	int		t_to_s;
	int		nb_of_t_e_p_m_e;
	int		t_id;
}				t_value;

void	error(int nb);
int		check_arg(char **argv);
int		philo(int argc, char **argv);
int		init_value(int argc, char **argv);
int		ft_atoi(const char *s, int *nb);

# endif
