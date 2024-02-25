#include "philo.h"

int check_args(t_arguments *arguments, char **argv)
{
  arguments->total_philos = ft_atoi(argv[1]);
  arguments->time_to_die = ft_atoi(argv[2]);
  arguments->time_to_eat = ft_atoi(argv[3]);
  arguments->time_to_sleep = ft_atoi(argv[4]);
  if(arguments->total_philos < 1 || arguments->time_to_die < 0 || arguments->time_to_eat < 0 || arguments->time_to_sleep < 0)
    return (1);
  if (argv[5])
  {
    arguments->num_of_eat = ft_atoi(argv[5]);
    if (arguments->num_of_eat <= 0)
      return (1);
  }
  else {
    arguments->num_of_eat = -1;
  }
  return (0);
}
