/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:00:58 by aduenas-          #+#    #+#             */
/*   Updated: 2024/02/28 20:46:56 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args(t_arguments *arguments, char **argv)
{
  arguments->total_philos = ft_atoi(argv[1]);
  arguments->time_to_die = ft_atoi(argv[2]);
  arguments->time_to_eat = ft_atoi(argv[3]);
  arguments->time_to_sleep = ft_atoi(argv[4]);
  arguments->died = 0;
  if(arguments->total_philos < 1 || arguments->time_to_die < 0 || arguments->time_to_eat < 0 || arguments->time_to_sleep < 0)
    return (1);
  if (argv[5])
  {
    arguments->num_of_eat = ft_atoi(argv[5]);
    if (arguments->num_of_eat <= 0)
      return (1);
  }
  else {
    arguments->num_of_eat = -1;
  }
  return (0);
}

long long	ft_gettime(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	*ft_thread(void *philo)
{
	t_philo	*philosopher;
	t_arguments	*arguments;

	philosopher = (t_philo *)philo;
  arguments = philosopher->arguments;
	if (philosopher->id % 2 == 0)
		usleep(10000);
	while (arguments->died && !arguments->num_of_eat)
	{
		philo_eat(philosopher);
	}
  return (NULL);
}
