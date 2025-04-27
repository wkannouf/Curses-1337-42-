# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 20:45:55 by wkannouf          #+#    #+#              #
#    Updated: 2025/03/10 20:35:09 by wkannouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_C = mendatory/client.c
SRC_S = mendatory/server.c
OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)

SRC_C_B = bonus/client_bonus.c
SRC_S_B = bonus/server_bonus.c
OBJ_C_B = $(SRC_C_B:.c=.o)
OBJ_S_B = $(SRC_S_B:.c=.o)

NAME = client
NAME_SERVER = server

NAME_B = client_bonus
NAME_SERVER_B = server_bonus

all: $(NAME) $(NAME_SERVER)

bonus: $(NAME_B) $(NAME_SERVER_B)

$(NAME): $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME)

$(NAME_SERVER): $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME_SERVER)

$(NAME_B): $(OBJ_C_B)
	$(CC) $(CFLAGS) $(OBJ_C_B) -o $(NAME_B)

$(NAME_SERVER_B): $(OBJ_S_B)
	$(CC) $(CFLAGS) $(OBJ_S_B) -o $(NAME_SERVER_B)

mendatory/%.o: mendatory/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_C) $(OBJ_S) $(OBJ_C_B) $(OBJ_S_B)

fclean: clean
	rm -rf $(NAME) $(NAME_SERVER) $(NAME_B) $(NAME_SERVER_B)

re: fclean all

.PHONY: clean
