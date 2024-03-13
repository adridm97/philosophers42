/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:01:02 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/13 23:40:53 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//se asigna espacio de memoria a los philosophers y 
//se le asigna su tenedor izquierdo y su tenedor izquierdo es una llamada al
//izquierdo del philosopher de su izquierda.
int	init_philosophers(t_arguments *args)
{
	int	i;

	i = -1;
	while (++i < args->total_philos)
	{
		args->philos[i].id = i + 1;
		args->philos[i].time_to_die = args->time_to_die;
		args->philos[i].time_eats = 0;
		args->philos[i].meal_finished = 0;
		args->philos[i].time_last_meal = args->first_timestamp;
		args->philos[i].right_fork = NULL;
		args->philos[i].left_fork = NULL;
		pthread_mutex_init(&args->philos[i].time_eat_mutex, NULL);
		args->philos[i].arguments = args;
	}
	return (0);
}

void	init_forks(t_arguments *args)
{
	int	i;

	i = -1;
	while (++i < args->total_philos)
		pthread_mutex_init(&args->forks_mutex[i], NULL);
	i = -1;
	while (++i < args->total_philos)
	{
		if (i == 0)
			args->philos[i].right_fork \
				= &args->forks_mutex[args->total_philos - 1];
		else
			args->philos[i].right_fork = &args->forks_mutex[i - 1];
		args->philos[i].left_fork = &args->forks_mutex[i % args->total_philos];
	}
}

void	*ft_thread(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	if (philosopher->id % 2 == 0)
		philo_sleep(500);
	while (get_end(philosopher->arguments) == 0)
	{
		take_forks(philosopher);
		philo_eat(philosopher);
		print_action("is sleeping", philosopher->id, philosopher->arguments);
		philo_sleep(philosopher->arguments->time_to_sleep);
		print_action("is thinking", philosopher->id, philosopher->arguments);
		if (get_end(philosopher->arguments) == 0)
			break ;
	}
	return (NULL);
}

int	start_threads(t_arguments *args)
{
	int	i;

	i = -1;
	args->first_timestamp = ft_gettime();
	while (++i < get_total_philo(args))
	{
		args->philos[i].time_last_meal = ft_gettime();
		pthread_create(&(args->philos[i].thread_id), \
				NULL, ft_thread, &args->philos[i]);
	}
	death_checker(args);
	i = -1;
	while (++i < args->total_philos)
		pthread_join(args->philos[i].thread_id, NULL);
	finish_dinner(args);
	return (1);
}

void	finish_dinner(t_arguments *args)
{
	int	i;

	i = -1;
	while (++i < args->total_philos)
		pthread_mutex_destroy(&args->forks_mutex[i]);
	pthread_mutex_destroy(&(args->writing));
	pthread_mutex_destroy(&args->meal_mutex);
	pthread_mutex_destroy(&args->dead_mutex);
	pthread_mutex_destroy(&args->time_mutex);
}
