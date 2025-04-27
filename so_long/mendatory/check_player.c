/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:52:30 by wkannouf          #+#    #+#             */
/*   Updated: 2025/03/29 22:19:24 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player(int x, int y, t_game *game)
{
	int	g_x;
	int	g_y;

	g_x = x / 64;
	g_y = y / 64;
	if (game->map[g_y][g_x] == '1')
		return (0);
	if (game->map[g_y][g_x] == 'E' && game->count_c != game->total_c)
		return (0);
	else if (game->map[g_y][g_x] == 'E' && game->count_c == game->total_c)
	{
		mlx_destroy_window(game->mlx, game->window);
		ft_putstr_fd("CONGRATULATION! YOU WIN\n", 2);
		exit (0);
	}
	else if (game->map[g_y][g_x] == 'C')
	{
		game->map[g_y][g_x] = '0';
		game->count_c++;
	}
	return (1);
}
