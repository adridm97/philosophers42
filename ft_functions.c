/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:03:08 by aduenas-          #+#    #+#             */
/*   Updated: 2024/02/25 11:03:11 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *str)
{
  long int res;;
  int i;
  int sign;

  res = 0;
  i = 0;
  sign = 1;
  while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
    i++;
  if(str[i] == '-')
    return (-1);
  if(str[i] == '+')
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