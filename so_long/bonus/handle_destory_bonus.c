/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_destory_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:52:46 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/07 15:50:55 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_destroy(t_game *game)
{
	ft_putstr_fd ("GAME OVER!! (Window Closed)\n", 2);
	mlx_destroy_window(game->mlx, game->window);
	exit (0);
	return (0);
}
