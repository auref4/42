/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:03:32 by auferran          #+#    #+#             */
/*   Updated: 2023/07/08 16:41:59 by auferran         ###   ########.fr       */
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
	int				*philo_eated;
	int				*is_dead;
	long int		timer_start;
}				t_value;

typedef struct s_mutex {
	pthread_mutex_t	timer;
	pthread_mutex_t	philo_eated;
	pthread_mutex_t	is_dead;
}				t_mutex;

typedef struct s_philo {
	int				index;
	pthread_mutex_t	fork;
	pthread_t		thread_id;
	long int		start_p;
	long int		last_m;
	int				meal_eated;
	t_value			*value;
	t_mutex			*mutex;
}				t_philo;

void	error(int nb);
int		check_arg(char **argv);
int		prep_philo(int argc, char **argv);
int		init_value(int argc, char **argv, t_value *value);
void	init_philo(t_philo *philo, t_value *value);
int		ft_atoi(const char *s, int *nb);
int		ft_strcmp(const char *first, const char *second);
void	philosophers(t_philo *philo, t_value value);
int		init_mutex(t_philo *philo, t_mutex *mutex);
void	*start_thread(void *philo);
void	print(t_philo *philo, char *str);
void	lock_modulo_2(t_philo *philo_thread);
void	unlock_modulo_2(t_philo *philo_thread);
void	lock(t_philo *philo_thread);
void	unlock(t_philo *philo_thread);
void	meal_eated(t_philo *philo_thread);
void	timer_start_philo(t_philo *philo_thread);
void	timer_last_meal(t_philo *philo_thread);
int		checker_death(t_philo *philo);
int		death_timer_1(t_philo *philo);
int		death_timer_2(t_philo *philo);
int		is_dead(t_philo *philo_thread);

#endif
