/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_image_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:52:56 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/09 20:39:35 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	xpm_file_to_image(t_game *game)
{
	game->mur_pass = mlx_xpm_file_to_image(game->mlx, "image/mur_pass.xpm", \
	&game->width, &game->height);
	game->door = mlx_xpm_file_to_image(game->mlx, "image/door.xpm", \
	&game->width, &game->height);
	game->cheese = mlx_xpm_file_to_image(game->mlx, "image/cheese.xpm", \
	&game->width, &game->height);
	game->img_down = mlx_xpm_file_to_image(game->mlx, "image/cat_devant.xpm", \
	&game->width, &game->height);
	game->img_up = mlx_xpm_file_to_image(game->mlx, "image/cat_arriere.xpm", \
	&game->width, &game->height);
	game->img_left = mlx_xpm_file_to_image(game->mlx, "image/cat_left.xpm", \
	&game->width, &game->height);
	game->img_right = mlx_xpm_file_to_image(game->mlx, "image/cat_right.xpm", \
	&game->width, &game->height);
	game->dog = mlx_xpm_file_to_image(game->mlx, "image/dog.xpm", \
	&game->width, &game->height);
	if (game->mur_pass == NULL || game->door == NULL || game->img_down == NULL \
	|| game->img_up == NULL || game->img_left == NULL || game->cheese == NULL \
	|| game->img_right == NULL || game->dog == NULL)
		return (ft_putstr_fd("ERROR! DOWLOAND IMAGES IS FAILED!\n", 2), 1);
	return (0);
}
