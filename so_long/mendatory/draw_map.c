/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:52:21 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/09 16:46:10 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_character(t_game *game)
{
	void	*img;

	if (game->pos == 'a')
		img = game->img_left;
	else if (game->pos == 'd')
		img = game->img_right;
	else if (game->pos == 'w')
		img = game->img_up;
	else
		img = game->img_down;
	mlx_put_image_to_window(game->mlx, game->window, img, game->x, game->y);
}

void	draw_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->mur_pass, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->door, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->cheese, x, y);
	else if (tile == 'P' && game->x == -1 && game->y == -1)
	{
		game->x = x;
		game->y = y;
	}
}

int	draw_map(t_game *game)
{
	game->height_y_map = 0;
	if (xpm_file_to_image(game) == 1)
		return (0);
	while (game->map[game->height_y_map])
	{
		game->width_x_map = 0;
		while (game->map[game->height_y_map][game->width_x_map])
		{
			draw_tile(game, game->map[game->height_y_map][game->width_x_map],
				game->width_x_map * 64, game->height_y_map * 64);
			game->width_x_map++;
		}
		game->height_y_map++;
	}
	draw_character(game);
	return (0);
}
