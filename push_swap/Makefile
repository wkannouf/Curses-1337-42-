# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 20:50:21 by wkannouf          #+#    #+#              #
#    Updated: 2025/04/15 07:17:58 by wkannouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/push_swap.c mandatory/op_a.c mandatory/op_b.c mandatory/utils.c mandatory/utils_linked_list.c mandatory/put_num.c mandatory/ft_split.c mandatory/mini_sort.c mandatory/sort.c
SRC_BONUS = bonus/push_swap_bonus.c bonus/op_a_bonus.c bonus/op_b_bonus.c bonus/utils_bonus.c bonus/utils_linked_list_bonus.c bonus/put_num_bonus.c bonus/ft_split_bonus.c bonus/utils2_bonus.c\
			bonus/get_next_line_bonus.c bonus/take_op_bonus.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $@

mandatory/%.o: mandatory/%.c mandatory/push_swap.h 
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/push_swap_bonus.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean
