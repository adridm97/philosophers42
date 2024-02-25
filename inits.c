
#include "philo.h"

int init_mutex(t_arguments *arguments)
{
  int i;

  i = arguments->total_philos;
  while(--i >= 0)
  {
    if(pthread_mutex_init(&(arguments->total_forks[i]), NULL))
      return (1);
  }
	return (0);
}

int	init_philosophers(t_arguments *arguments)
{
	int i;

	i = arguments->total_philos;
	while (--i >= 0)
	{
		arguments->philo[i].id = i;
		arguments->philo[i].left_fork = i;
		arguments->philo[i].right_fork = (i + 1) % arguments->total_philos;
	}
	return (0);
}

/*void init_forks(t_arguments *arguments)
{
  int i;
  
  i = -1;
  while(++i < arguments->total_philos)
  {
    pthread_mutex_init(&arguments->total_forks[i], NULL);
  }
  i = -1;
  while(++i < arguments->total_philos)
  {
    if (i == 0)
			arguments->philo[i].right_fork = &arguments->total_forks[arguments->total_philos - 1];
		else
			arguments->philo[i].right_fork = &arguments->total_forks[i - 1];
		arguments->philo[i].left_fork = &arguments->total_forks[i % arguments->total_philos];
  }
}*/
