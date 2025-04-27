/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:15:22 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/09 20:34:09 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, char *path_map)
{
	if (!check_map(game, path_map, 0, 0) || \
		ft_strncmp(path_map + (ft_strlen(path_map) - 4), ".ber", 4) != 0)
		return (0);
	if (!check_map_border(game->map))
		return (free_map(game->map), 0);
	if (!is_path_valid(game->map) || !is_path_valid_2(game->map))
		return (free_map(game->map), 0);
	game->width_background = ft_strlen(game->map[0]) * 64;
	game->height_background = 0;
	while (game->map[game->height_background] != NULL)
		game->height_background++;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_map(game->map), 0);
	game->window = mlx_new_window(game->mlx, game->width_background, \
			game->height_background * 64, "SO_LONG");
	if (!game->window)
	{
		free(game->mlx);
		free_map(game->map);
		return (0);
	}
	return (1);
}
