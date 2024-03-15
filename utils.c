/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:00:58 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/13 23:20:25 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(t_arguments *arguments, char **argv)
{
	arguments->total_philos = ft_atoi(argv[1]);
	arguments->time_to_die = ft_atoi(argv[2]);
	arguments->time_to_eat = ft_atoi(argv[3]);
	arguments->time_to_sleep = ft_atoi(argv[4]);
	arguments->dead = 0;
	arguments->total_eat = -1;
	if (argv[5])
		arguments->total_eat = ft_atoi(argv[5]);
	arguments->first_timestamp = ft_gettime();
	arguments->dead = 0;
	pthread_mutex_init(&arguments->writing, NULL);
	pthread_mutex_init(&arguments->fin_meal_mutex, NULL);
	pthread_mutex_init(&arguments->dead_mutex, NULL);
	pthread_mutex_init(&arguments->time_mutex, NULL);
	if (allocate(arguments) == 1)
		return (1);
	return (0);
}

long	ft_gettime(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	philo_sleep(unsigned long time, t_arguments *args)
{
	unsigned long	start;

	start = ft_gettime();
	while (get_end(args) == 0)
	{
		if (ft_gettime() - start >= time)
			break ;
		usleep(50);
	}
}

int	allocate(t_arguments *args)
{
	args->forks_mutex = (pthread_mutex_t *)malloc \
						(sizeof(pthread_mutex_t) * args->total_philos);
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

void	death_checker(t_arguments *args)
{
	int	i;

	while (get_end(args) == 0)
	{
		i = 0;
		while (i < get_total_philo(args) && get_end(args) == 0)
		{
			if (death_wait(args, i) == 1 || get_end(args) == 1)
				break ;
			i++;
		}
		check_full(args);
		philo_sleep(args->time_to_die, args);
	}
}
