/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:10:06 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/13 23:41:17 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action("has taken a fork", philo->id, philo->arguments);
	pthread_mutex_lock(philo->right_fork);
	print_action("has taken a fork", philo->id, philo->arguments);
}

void	philo_eat(t_philo *philo)
{
	t_arguments	*args;

	args = philo->arguments;
	print_action("is eating", philo->id, args);
//	philo_sleep(args->time_to_eat);
	philo->time_eats++;
	if (philo->time_eats == get_total_eats(args))
		set_finish_meal(philo);
	pthread_mutex_lock(&philo->time_eat_mutex);
	philo->time_last_meal = ft_gettime();
	pthread_mutex_unlock(&philo->time_eat_mutex);
	drop_fork(philo);
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	check_full(t_arguments *args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < get_total_philo(args))
	{
		pthread_mutex_lock(&args->dead_mutex);
		if (args->philos[i].meal_finished == 1)
		{
			pthread_mutex_unlock(&args->dead_mutex);
			count++;
		}
		pthread_mutex_unlock(&args->dead_mutex);
		if (count == get_total_philo(args))
			set_finish(args);
		i++;
	}
}

int	single_philo(t_arguments *args)
{
	args->first_timestamp = ft_gettime();
	print_action("has taken a fork", 1, args);
	philo_sleep(args->time_to_die);
	print_action("is dead", 1, args);
	finish_dinner(args);
	ft_clear(args);
	return (1);
}
