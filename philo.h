/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:03:20 by aduenas-          #+#    #+#             */
/*   Updated: 2024/02/28 21:16:35 by aduenas-         ###   ########.fr       */
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
  int				            id;
  pthread_mutex_t	      *left_fork;
  pthread_mutex_t	      right_fork;
  long				          time_last_meal;
  struct s_arguments		*arguments;
  pthread_t             tread_id;
}	t_philo;

typedef struct s_arguments
{
  int		          total_philos;
  long		        time_to_eat;
  long		        time_to_die;
  long		        time_to_sleep;
  int		          num_of_eat;
  int		          died;
  long long       first_timestamp;
  pthread_mutex_t writing;
  t_philo	        *philos;
}	t_arguments;

//-----inits.c------

int	init_mutex(t_arguments *arguments);
int	init_philosophers(t_arguments *arguments);
int	start_threads(t_arguments *arguments);
void	*ft_thread(void *philosopher);

//-----utils.c------

int	check_args(t_arguments *arguments, char **argv);
long long	ft_gettime(void);

//-----philo_functions.c------

void		philo_eat(t_philo *philo);

//-----ft_functions.c-------

int	ft_atoi(char *str);
void  print_action(char *str, int id, t_arguments *args);

#endif
