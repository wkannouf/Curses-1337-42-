# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 22:48:43 by wkannouf          #+#    #+#              #
#    Updated: 2025/05/18 23:24:55 by wkannouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = philo.c time.c check_death.c utils.c
OBJS = philo.o time.o check_death.o utils.o

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
