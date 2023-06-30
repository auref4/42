/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:03:32 by auferran          #+#    #+#             */
/*   Updated: 2023/06/23 19:06:40 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_value {
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_meal;
	pthread_mutex_t	print;
	long int		timer_start;
	struct timeval	start;
	struct timeval	inwhile;
}				t_value;

typedef struct s_philo {
	int				index;
	pthread_mutex_t	fork;
	pthread_t		thread_id;
	struct timeval	eating;
	struct timeval	inwhile_eating;
	struct timeval	start_philo;
	struct timeval	last_meal;
	struct timeval	sleeping;
	struct timeval	inwhile_sleeping;
	struct timeval	inwhile_death;
	int				i;
	t_value			value;
}				t_philo;

void	error(int nb);
int		check_arg(char **argv);
int		philo(int argc, char **argv);
int		init_value(int argc, char **argv, t_value *value);
void	init_philo(t_philo *philo, t_value value);
int		ft_atoi(const char *s, int *nb);
void	create_thread(t_philo *philo, t_value value);
void	print_timer(t_philo *philo);
int		eating_timer(t_philo *philo_thread);
int		sleeping_timer(t_philo *philo_thread);
void	lock_modulo_2(t_philo * philo_thread);
void	unlock_modulo_2(t_philo *philo_thread);
void	lock(t_philo * philo_thread);
void	unlock(t_philo *philo_thread);
int		death_timer_1(t_philo *philo);
int		death_timer_2(t_philo *philo);

#endif
