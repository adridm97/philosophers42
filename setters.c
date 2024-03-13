/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:33:55 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/13 20:52:09 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_finish_meal(t_philo *philo)
{
	int	finished;

	finished = 1;
	pthread_mutex_lock(&philo->arguments->dead_mutex);
	philo->meal_finished = finished;
	pthread_mutex_unlock(&philo->arguments->dead_mutex);
}

void	set_finish(t_arguments *args)
{
	int	finish;

	finish = 1;
	pthread_mutex_lock(&args->dead_mutex);
	args->dead = finish;
	pthread_mutex_unlock(&args->dead_mutex);
}
