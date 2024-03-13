/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:01:04 by aduenas-          #+#    #+#             */
/*   Updated: 2024/03/13 20:50:51 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arguments	arguments;

	if (argc != 5 && argc != 6)
	{
		printf("Error with number of arguments, valid 4 or 5.\n");
		return (1);
	}
	if (check_args(&arguments, argv) == 1)
	{
		printf("Error with arguments.\n");
		return (1);
	}
	if (init_philosophers(&arguments) == 1)
		return (1);
	init_forks(&arguments);
	if (arguments.total_philos == 1)
	{
		if (single_philo(&arguments) == 1)
			return (1);
	}
	if (start_threads(&arguments) == 1)
		return (1);
}
