# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 11:02:29 by aduenas-          #+#    #+#              #
#    Updated: 2024/03/03 21:51:38 by aduenas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = philo
HEADER = philo.h
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread
#-fsanitize=thread


SRC = main.c inits.c utils.c ft_functions.c philo_functions.c

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
