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

typedef struct s_value {
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_meal;
	pthread_mutex_t	synchro;
	long int		timer_start;
	struct timeval	start;
	struct timeval	inwhile;
}				t_value;

typedef struct s_philo {
	int				index;
	pthread_mutex_t	fork;
	pthread_t		thread_id;
	struct timeval	start_philo;
	t_value			value;
}				t_philo;

void	error(int nb);
int		check_arg(char **argv);
int		philo(int argc, char **argv);
int		init_value(int argc, char **argv, t_value *value);
void	init_philo(t_philo *philo, t_value value);
int		ft_atoi(const char *s, int *nb);
void	manage_thread(t_philo *philo, t_value value);
void	print_timer(t_philo *philo);

#endif
