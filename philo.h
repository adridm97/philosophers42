/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:03:20 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/04 20:28:47 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
  int						id;
  int						number_of_eats;
  pthread_mutex_t			*left_fork;
  pthread_mutex_t			right_fork;
  long						time_last_meal;
  struct s_arguments		*arguments;
  pthread_t					thread_id;
}	t_philo;

typedef struct s_arguments
{
  int				total_philos;
  long				time_to_eat;
  long				time_to_die;
  long				time_to_sleep;
  int				total_eat;
  int				died;
  int				all_eat;
  long long			first_timestamp;
  pthread_mutex_t 	writing;
  pthread_mutex_t	meal;
  pthread_mutex_t	dead;
  pthread_mutex_t totals;
  t_philo			*philos;
}	t_arguments;

//-----inits.c------

int	init_philosophers(t_arguments *arguments);
int	start_threads(t_arguments *arguments);
void	death_checker(t_arguments *arguments, t_philo *philo);
void	finish_dinner(t_arguments *arguments, t_philo *philo);

//-----utils.c------

int	check_args(t_arguments *arguments, char **argv);
long long	ft_gettime(void);
void		*ft_thread(void *);
void		philo_sleep(long long time_to_eat, t_arguments *arguments);

//-----philo_functions.c------

void		philo_eat(t_philo *philo);

//-----ft_functions.c-------

int	ft_atoi(char *str);
void  print_action(char *str, int id, t_arguments *args);

#endif
