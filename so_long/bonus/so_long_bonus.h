/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:41:30 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/09 22:34:06 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define KEY_ESC 53
# define CROIX 17
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define BUFFER_SIZE 5

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

typedef struct data
{
	void	*window;
	void	*mlx;
	void	*img_left;
	void	*img_right;
	void	*img_down;
	void	*img_up;
	void	*background;
	void	*mur;
	void	*mur_top;
	void	*mur_right;
	void	*mur_left;
	void	*mur_pass;
	void	*banner;
	void	*door;
	void	*cat;
	void	*cheese;
	void	*dog;
	int		width_background;
	int		height_background;
	int		width;
	int		height;
	int		width_x_map;
	int		height_y_map;
	char	tmp;
	int		check;
	int		x;
	int		y;
	int		move_x;
	int		move_y;
	char	**map;
	char	pos;
	int		total_c;
	int		count_c;
	int		count_move;
	int		a;
}	t_game;

int		draw_map(t_game *game);
int		xpm_file_to_image(t_game *game);
int		check_player(int x, int y, t_game *game);
int		key_press(int keycode, t_game *game);
int		xpm_file_to_image(t_game *game);
int		handle_destroy(t_game *game);
void	handle_mlx_hooks(t_game *game);
int		check_map(t_game *game, char *path_map, int p, int e);
int		init_game(t_game *game, char *path_map);
char	**check_map_border(char **map);
char	*get_next_line(int fd);
void	free_map(char **map);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
int		is_path_valid(char **map);
int		is_path_valid_2(char **map);

#endif