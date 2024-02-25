
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
  int id;
  int left_fork;
  int right_fork;
} t_philo;

typedef struct s_arguments
{
  int total_philos;
  int time_to_eat;
  int time_to_die;
  int time_to_sleep;
  int num_of_eat;
  pthread_mutex_t *total_forks;
  t_philo *philo;
} t_arguments;

//-----inits.c------

int init_mutex(t_arguments *arguments);
int	init_philosophers(t_arguments *arguments);
//void init_forks(t_arguments *arguments);

//-----utils.c------

int check_args(t_arguments *arguments, char **argv);

//-----ft_functions.c-------

int ft_atoi(char *str);

#endif
