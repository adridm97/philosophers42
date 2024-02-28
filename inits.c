/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:01:02 by aduenas-          #+#    #+#             */
/*   Updated: 2024/02/25 16:25:58 by aduenas-         ###   ########.fr       */
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
		pthread_mutex_init(&args->philos->right_fork, NULL);
	}
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
	while (i < args->total_philos)
	{
		if (pthread_create(&(args->philos[i]), NULL, ft_thread, &(args->philos[i])))
			return (1);
		args->philos[i].time_last_meal = ft_gettime();
		i++;
	}
}
