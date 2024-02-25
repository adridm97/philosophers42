CC = gcc
NAME = philo
HEADER = philo.h
CFLAGS = -Wall -Wextra -Werror -g


SRC = main.c inits.c utils.c ft_functions.c

OBJS = ${SRC:.c=.o}

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME} Makefile

${NAME}: ${OBJS} ${HEADER}
	${CC} ${CFLAGS} ${OBJS} -o $@ 

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: re clean fclean all
