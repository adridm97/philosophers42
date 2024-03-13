/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:03:08 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/13 23:49:52 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	long int	res;
	int			i;
	int			sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i++] - '0');
		else
			return (-1);
	}
	return (res * sign);
}

void	print_action(char *str, int id, t_arguments *args)
{
	long long	start;
	long long	i;

	pthread_mutex_lock(&args->time_mutex);
	start = args->first_timestamp;
	pthread_mutex_unlock(&args->time_mutex);
	i = ft_gettime() - start;
	pthread_mutex_lock(&args->writing);
	printf("%lli ", i);
	printf("%i ", id);
	printf("%s\n", str);
	pthread_mutex_unlock(&args->writing);
}

int	ft_clear(t_arguments *args)
{
	if (args->forks_mutex)
		free(args->forks_mutex);
	if (args->philos)
		free(args->philos);
	return (0);
}

int	death_wait(t_arguments *args, int i)
{
	if (ft_gettime() - args->philos[i].time_last_meal >= get_time_to_die(args))
	{
		set_finish(args);
		print_action("is dead", args->philos[i].id, args);
		return (1);
	}
	return (0);
}
