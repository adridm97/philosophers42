/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:10:06 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/06 21:57:48 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	t_arguments	*args;
	args = philo->arguments;
	pthread_mutex_lock(philo->left_fork);
	print_action("has taken a fork", philo->id, args);
	pthread_mutex_lock(&philo->right_fork);
	print_action("has taken a fork", philo->id, args);
	print_action("is eating", philo->id, args);
	pthread_mutex_lock(&args->meal);
	philo->time_last_meal = ft_gettime();
	philo_sleep(args->time_to_eat, args);
	pthread_mutex_unlock(&args->meal);
	pthread_mutex_lock(&args->totals);
	philo->number_of_eats += 1;
	pthread_mutex_unlock(&args->totals);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}
