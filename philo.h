/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:03:20 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/13 23:12:17 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_arguments	t_arguments;

typedef struct s_philo
{
	int				id;
	long			time_to_die;
	int				time_eats;
	int				meal_finished;
	long			time_last_meal;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	time_eat_mutex;
	t_arguments		*arguments;
	pthread_t		thread_id;
}	t_philo;

typedef struct s_arguments
{
	int				total_philos;
  	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				total_eat;
  int				dead;
	long long		first_timestamp;
	pthread_mutex_t	writing;
	pthread_mutex_t	fin_meal_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	*forks_mutex;
	t_philo			*philos;
}	t_arguments;

//-----inits.c------

int		init_philosophers(t_arguments *arguments);
void	init_forks(t_arguments *arguments);
int		start_threads(t_arguments *arguments);
void	finish_dinner(t_arguments *arguments);

//-----utils.c------

int		check_args(t_arguments *arguments, char **argv);
long	ft_gettime(void);
void	philo_sleep(unsigned long time_to_eat, t_arguments *arguments);
int		allocate(t_arguments *arguments);
void	death_checker(t_arguments *arguments);

//-----philo_functions.c------

void	philo_eat(t_philo *philo);
void	check_full(t_arguments *arguments);
int		single_philo(t_arguments *arguments);
void    drop_fork(t_philo *philo);
void    take_forks(t_philo *philo);

//-----ft_functions.c-------

int		ft_atoi(char *str);
void	print_action(char *str, int id, t_arguments *arguments);
int		ft_clear(t_arguments *arguments);
int		death_wait(t_arguments *arguments, int i);

//------getters.c----------

int		get_total_philo(t_arguments *arguments);
int		get_end(t_arguments *arguments);
int		get_total_eats(t_arguments *arguments);
int		get_time_last_meal(t_philo *philo);
long	get_time_to_die(t_arguments *args);

//-----setters.c---------

void	set_finish_meal(t_philo *philo);
void	set_finish(t_arguments *arguments);

#endif
