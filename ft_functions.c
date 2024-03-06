/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:03:08 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/06 19:51:52 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *str)
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
	while(str[i])
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
	pthread_mutex_lock(&args->writing);
	if (!(args->died))
	{
		printf("%lli ", ft_gettime() - args->first_timestamp);
		printf("%i ", id);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&args->writing);
}
