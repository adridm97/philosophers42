/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:10:06 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/10 23:18:37 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	t_arguments	*args;
	args = philo->arguments;
	pthread_mutex_lock(philo->left_fork);
	print_action("has taken a fork", philo->id, args);
	pthread_mutex_lock(philo->right_fork);
	print_action("has taken a fork", philo->id, args);
	print_action("is eating", philo->id, args);
	philo_sleep(args->time_to_eat, args);
	philo->time_eats += 1;
	if (philo->time_eats == get_total_eats(args))
		set_finish_meal(philo);
	pthread_mutex_lock(&philo->time_eat_mutex);
	philo->time_last_meal = ft_gettime();
	pthread_mutex_unlock(&philo->time_eat_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	check_full(t_arguments *args)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < get_total_philo(args))
	{
		pthread_mutex_lock(&args->dead_mutex);
		if (args->philos[i].meal_finished == true)
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
