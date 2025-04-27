# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 19:01:02 by wkannouf          #+#    #+#              #
#    Updated: 2025/04/09 22:33:04 by wkannouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

SRC = mendatory/check_key.c mendatory/check_player.c mendatory/draw_map.c mendatory/handle_destory.c \
	mendatory/handle_mlx_hook.c mendatory/initialiser_game.c mendatory/so_long.c mendatory/xpm_to_image.c \
	mendatory/free.c mendatory/check_map.c mendatory/check_map2.c

SRC_BONUS = bonus/check_key_bonus.c bonus/check_player_bonus.c bonus/draw_map_bonus.c bonus/handle_destory_bonus.c \
	bonus/handle_mlx_hook_bonus.c bonus/initialiser_game_bonus.c bonus/so_long_bonus.c bonus/xpm_to_image_bonus.c \
	bonus/free_bonus.c mendatory/check_map.c mendatory/check_map2.c

SRC_UTILS = mendatory/utils/ft_atoi.c mendatory/utils/ft_bzero.c mendatory/utils/ft_calloc.c mendatory/utils/ft_itoa.c \
		mendatory/utils/ft_putchar_fd.c mendatory/utils/ft_putnbr_fd.c mendatory/utils/ft_putstr_fd.c \
		mendatory/utils/ft_strdup.c mendatory/utils/ft_strjoin.c mendatory/utils/ft_strlcpy.c mendatory/utils/ft_strlen.c \
		mendatory/utils/ft_strncmp.c mendatory/utils/ft_strchr.c mendatory/utils/ft_substr.c mendatory/utils/ft_split.c mendatory/utils/get_next_line.c

SRC_UTILS_BONUS = bonus/utils_bonus/ft_atoi_bonus.c bonus/utils_bonus/ft_bzero_bonus.c bonus/utils_bonus/ft_calloc_bonus.c bonus/utils_bonus/ft_itoa_bonus.c \
		bonus/utils_bonus/ft_putchar_fd_bonus.c bonus/utils_bonus/ft_putnbr_fd_bonus.c bonus/utils_bonus/ft_putstr_fd_bonus.c \
		bonus/utils_bonus/ft_strdup_bonus.c bonus/utils_bonus/ft_strjoin_bonus.c bonus/utils_bonus/ft_strlcpy_bonus.c bonus/utils_bonus/ft_strlen_bonus.c \
		bonus/utils_bonus/ft_strncmp_bonus.c bonus/utils_bonus/ft_strchr_bonus.c bonus/utils_bonus/ft_substr_bonus.c bonus/utils_bonus/ft_split_bonus.c bonus/utils_bonus/get_next_line_bonus.c

OBJS = $(SRC:.c=.o)
OBJL = $(SRC_UTILS:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)
OBJL_BONUS = $(SRC_UTILS_BONUS:.c=.o)

NAME = so_long
NAME_BONUS = so_long_bonus

all: $(NAME)

$(NAME): $(OBJS) $(OBJL)
	$(CC) $(CFLAGS) $(MLX) $(OBJS) $(OBJL) -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(OBJL_BONUS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS_BONUS) $(OBJL_BONUS) -o $@

mendatory/%.o: mendatory/%.c mendatory/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJL) $(OBJS_BONUS) $(OBJL_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean
