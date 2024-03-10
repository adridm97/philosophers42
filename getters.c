
#include "philo.h"

int get_total_philo(t_arguments *args)
{
    int total;

    pthread_mutex_lock(&args->time_mutex);
    total = args->total_philos;
    pthread_mutex_unlock(&args->time_mutex);
    return (total);    
}

int get_end(t_arguments *args)
{
    bool    finish;

    pthread_mutex_lock(&args->dead_mutex);
    finish = args->dead;
    pthread_mutex_lock(&args->dead_mutex);
    return (finish);
}

int get_total_eats(t_arguments *args)
{
    int total;

    pthread_mutex_lock(&args->meal_mutex);
    total = args->total_eat;
    pthread_mutex_unlock(&args->meal_mutex);
    return (total);
}