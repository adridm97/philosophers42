
#include "philo.h"

void    set_finish_meal(t_philo *philo)
{
    bool finished;

    finished = true;
    pthread_mutex_lock(&philo->arguments->dead_mutex);
    philo->meal_finished = finished;
    pthread_mutex_unlock(&philo->arguments->dead_mutex);
}

void    set_finish(t_arguments *args)
{
    bool finish;

    finish = true;
    pthread_mutex_lock(&args->dead_mutex);
    args->dead = true;
    pthread_mutex_unlock(&args->dead_mutex);
}