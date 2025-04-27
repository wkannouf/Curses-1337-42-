/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:52:36 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/06 18:45:27 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_a(int keycode, t_game *game)
{
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->check = check_player(game->x - 64, game->y, game);
		game->pos = 'a';
		if (game->check)
		{
			game->count_move++;
			game->x -= 64;
		}
	}
	else
		mlx_put_image_to_window(game->mlx, game->window, \
		game->img_down, game->x, game->y);
}

void	key_d(int keycode, t_game *game)
{
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->check = check_player(game->x + 64, game->y, game);
		game->pos = 'd';
		if (game->check)
		{
			game->count_move++;
			game->x += 64;
		}
	}
	else
		mlx_put_image_to_window(game->mlx, game->window, \
		game->img_down, game->x, game->y);
}

void	key_w(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->check = check_player(game->x, game->y - 64, game);
		game->pos = 'w';
		if (game->check)
		{
			game->count_move++;
			game->y -= 64;
		}
	}
	else
		mlx_put_image_to_window(game->mlx, game->window, \
		game->img_down, game->x, game->y);
}

void	key_s(int keycode, t_game *game)
{
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->check = check_player(game->x, game->y + 64, game);
		game->pos = 's';
		if (game->check)
		{
			game->count_move++;
			game->y += 64;
		}
	}
	else
		mlx_put_image_to_window(game->mlx, game->window, \
		game->img_down, game->x, game->y);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		handle_destroy(game);
	key_a(keycode, game);
	key_d(keycode, game);
	key_w(keycode, game);
	key_s(keycode, game);
	check_player(game->x, game->y, game);
	mlx_clear_window(game->mlx, game->window);
	draw_map(game);
	return (0);
}
