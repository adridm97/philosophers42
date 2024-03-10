/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:03:20 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/06 22:24:52 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_arguments	t_arguments;

typedef enum e_status
{
	DIED,
	EATING,
	FORK,
	SLEEP,
	THINK,
	EXIT
}	t_status;

typedef struct s_philo
{
  int						  id;
  long			      time_to_die;
  int						  time_eats;
  bool			      meal_finished;
  long					  time_last_meal;
  pthread_mutex_t	*right_fork;
  pthread_mutex_t *left_fork;
  pthread_mutex_t *time_eat_mutex;
  t_arguments		  *arguments;
  pthread_t		    thread_id;
}	t_philo;

typedef struct s_arguments
{
  int				total_philos;
  int				time_to_eat;
  int				time_to_die;
  int				time_to_sleep;
  bool			dead;
  int				total_eat;
  long long			first_timestamp;
  pthread_mutex_t 	writing;
  pthread_mutex_t	meal_mutex;
  pthread_mutex_t	dead_mutex;
  pthread_mutex_t	time_mutex;
  pthread_mutex_t	*forks_mutex;
  t_philo			*philos;
}	t_arguments;

//-----inits.c------

int	init_philosophers(t_arguments *arguments);
void  init_forks(t_arguments *argumentss);
int	start_threads(t_arguments *arguments);
void	death_checker(t_arguments *arguments);
void	finish_dinner(t_arguments *arguments);

//-----utils.c------

int	check_args(t_arguments *arguments, char **argv);
long long	ft_gettime(void);
void		*ft_thread(void *);
void		philo_sleep(long long time_to_eat, t_arguments *arguments);
int     allocate(t_arguments *arguments);

//-----philo_functions.c------

void		philo_eat(t_philo *philo);
void  check_full(t_arguments *arguments);

//-----ft_functions.c-------

int	ft_atoi(char *str);
void  print_action(char *str, int id, t_arguments *arguments);
int   ft_clear(t_arguments *arguments);

//------getters.c----------

int get_total_philo(t_arguments *arguments);
int get_end(t_arguments *arguments);
int get_total_eats(t_arguments *arguments);

//-----setters.c---------

void  set_finish_meal(t_philo *philo);
void  set_finish(t_arguments *arguments);

#endif
