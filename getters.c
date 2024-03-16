/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:31:01 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/16 13:34:36 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_total_philo(t_arguments *args)
{
	int	total;

	pthread_mutex_lock(&args->time_mutex);
	total = args->total_philos;
	pthread_mutex_unlock(&args->time_mutex);
	return (total);
}

long	get_time_to_die(t_arguments *args)
{
	long	time;

	pthread_mutex_lock(&args->fin_meal_mutex);
	time = args->time_to_die;
	pthread_mutex_unlock(&args->fin_meal_mutex);
	return (time);
}

int	get_end(t_arguments *args)
{
	int	finish;

	pthread_mutex_lock(&args->dead_mutex);
	finish = args->dead;
	pthread_mutex_unlock(&args->dead_mutex);
	return (finish);
}

int	get_total_eats(t_arguments *args)
{
	int	total;

	pthread_mutex_lock(&args->fin_meal_mutex);
	total = args->total_eat;
	pthread_mutex_unlock(&args->fin_meal_mutex);
	return (total);
}
