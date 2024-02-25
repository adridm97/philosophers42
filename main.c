
#include "philo.h"

int main(int argc, char **argv)
{
  t_arguments arguments;
  if(argc != 5 && argc != 6)
  {
    printf("Error with number of arguments, valid 4 or 5.\n");
    return (1);
  }
  if(check_args(&arguments, argv) == 1)
  {
    printf("Error with arguments.\n");
    return (1);
  }
  if(init_mutex(&arguments) == 1)
  {
    printf("Error initializing mutex.\n");
    return (1);
  }
  init_philosophers(&arguments);
  //init_forks(&arguments);
}
