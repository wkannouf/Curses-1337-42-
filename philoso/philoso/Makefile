# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 22:48:43 by wkannouf          #+#    #+#              #
#    Updated: 2025/06/03 00:43:22 by wkannouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = philo.c atoi.c routine.c time.c check_died.c creat_philo.c init.c
OBJS = philo.o atoi.o routine.o time.o check_died.o creat_philo.o init.o

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
