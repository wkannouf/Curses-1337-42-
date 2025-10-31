# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 20:24:22 by wkannouf          #+#    #+#              #
#    Updated: 2025/10/20 20:26:57 by wkannouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = megaphone.cpp
O_FILES = megaphone.o

NAME = megaphone

all: $(NAME)

$(NAME): $(O_FILES)
	$(CC) $(FLAGS) $(O_FILES) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
