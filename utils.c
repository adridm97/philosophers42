/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:00:58 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/10 23:37:04 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args(t_arguments *arguments, char **argv)
{
  	arguments->total_philos = ft_atoi(argv[1]);
  	arguments->time_to_die = ft_atoi(argv[2]);
  	arguments->time_to_eat = ft_atoi(argv[3]);
  	arguments->time_to_sleep = ft_atoi(argv[4]);
  	arguments->dead = 0;
	arguments->total_eat = -1;
	if(arguments->total_philos < 2 || arguments->time_to_die < 0 || arguments->time_to_eat < 0 || arguments->time_to_sleep < 0)
	return (1);
	if (argv[5])
	{
		arguments->total_eat = ft_atoi(argv[5]);
	}
	arguments->first_timestamp = ft_gettime();
	arguments->dead = false;
	pthread_mutex_init(&arguments->writing, NULL);
	pthread_mutex_init(&arguments->meal_mutex, NULL);
	pthread_mutex_init(&arguments->dead_mutex, NULL);
	pthread_mutex_init(&arguments->time_mutex, NULL);
	if(allocate(arguments) == 1)
		return (1);
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

	philosopher = (t_philo *)philo;
	if (philosopher->id % 2 == 0)
		usleep(100);
	while (get_end(philosopher->arguments) == false)
	{
		philo_eat(philosopher);
		print_action("is sleeping", philosopher->id, philosopher->arguments);
		philo_sleep(philosopher->arguments->time_to_sleep, philosopher->arguments);
		print_action("is thinking", philosopher->id, philosopher->arguments);
		if (get_end(philosopher->arguments) == true)
			break ;
	}
  return (NULL);
}

void	philo_sleep(long long time, t_arguments *args)
{
	long long	i;

	i = ft_gettime();
	while (get_end(args))
	{
		if ((ft_gettime() - i) < time)
			break ;
		usleep(100);
	}
}

int allocate(t_arguments *args)
{
	args->forks_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args->total_philos);
	if (!args->forks_mutex)
	{
		finish_dinner(args);
		return (1);
	}
	args->philos = (t_philo *)malloc(sizeof(t_philo) * args->total_philos);
	if (!args->philos)
	{
		finish_dinner(args);
		return (1);
	}
	return (0);
}
