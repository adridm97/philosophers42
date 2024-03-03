/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:01:02 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/03 21:48:27 by aduenas-         ###   ########.fr       */
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
	args->philos = (t_philo *)malloc(sizeof(t_philo) * args->total_philos);
	if (!args->philos)
		return (1);
	while (++i < args->total_philos)
	{
		args->philos[i].id = i + 1;
		args->philos[i].arguments = args;
		args->philos[i].number_of_eats = 0;
		if (pthread_mutex_init(&args->philos->right_fork, NULL))
		return (1);
	}
	if (pthread_mutex_init(&args->writing, NULL))
		return (1);
	if (pthread_mutex_init(&args->meal, NULL))
		return (1);
	if (args->total_philos > 1)
	{
		i = 0;
		if(i == 0)
			args->philos[i].left_fork = &args->philos[args->total_philos].right_fork;
		while (++i < args->total_philos)
			args->philos[i].left_fork = &args->philos[i - 1].right_fork;
	}
	return (0);
}

int	start_threads(t_arguments *args)
{
	int	i;

	i = 0;
	args->first_timestamp = ft_gettime();
	while (i < args->total_philos)
	{
		if (pthread_create(&(args->philos[i].thread_id), NULL, ft_thread, &(args->philos[i])))
			return (1);
		args->philos[i].time_last_meal = ft_gettime();
		i++;
	}
	death_checker(args, args->philos);
	finish_dinner(args, args->philos);
	return (0);
}

void	death_checker(t_arguments *args, t_philo *philo)
{
	int	i;

	while ((args->all_eat) == 0)
	{
		i = -1;
		while(++i < args->total_philos && !(args->died))
		{
			pthread_mutex_lock(&args->meal);
			if (ft_gettime() - philo[i].time_last_meal > args->time_to_die)
			{
				print_action("died", i, args);
				args->died = 1;
			}
			pthread_mutex_unlock(&args->meal);
			usleep(100);
		}
		if (args->died == 1)
			break ;
		i = 0;
		while (args->total_eat != -1 && i < args->total_philos && philo[i].number_of_eats == args->total_eat)
			i++;
		if (i == args->total_philos)
			args->all_eat = 1;
	}
}

void	finish_dinner(t_arguments *args, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < args->total_philos)
		pthread_join(philo[i].thread_id, NULL);
	i = -1;
	while (++i < args->total_philos)
		pthread_mutex_destroy(&philo->right_fork);
	pthread_mutex_destroy(&(args->writing));
}
