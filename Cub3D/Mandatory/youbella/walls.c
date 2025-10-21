/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:32:07 by youbella          #+#    #+#             */
/*   Updated: 2025/10/06 16:55:46 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	put_pixels(mlx_texture_t *texture,
						t_data *data, int start, int index)
{
	size_t	r;
	size_t	g;
	size_t	b;
	size_t	a;
	size_t	color;

	r = texture->pixels[index + 0];
	g = texture->pixels[index + 1];
	b = texture->pixels[index + 2];
	a = texture->pixels[index + 3];
	color = (r << 24) | (g << 16) | (b << 8) | a;
	mlx_put_pixel(data->game->img, data->walls->columns, start, color);
}

static void	get_pixels(mlx_texture_t *texture,
					int l_height, t_data *data)
{
	int	d;
	int	index;
	int	tex_y;

	if ((data->walls->side == 0 && data->walls->ray_dir_x > 0)
		|| (data->walls->side == 1 && data->walls->ray_dir_y < 0))
		data->walls->tex_x = texture->width - data->walls->tex_x - 1;
	while (data->walls->draw_start < data->walls->draw_end)
	{
		d = (data->walls->draw_start * 256 - HEIGHT * 128 + l_height * 128);
		tex_y = ((d * texture->height) / l_height) / 256;
		index = (tex_y * texture->width + data->walls->tex_x) * 4;
		put_pixels(texture, data, data->walls->draw_start, index);
		data->walls->draw_start++;
	}
}

static mlx_texture_t	*ft_texture(t_walls *walls)
{
	if (walls->side == 0)
	{
		if (walls->step_x == -1)
			return (walls->we_img);
		else
			return (walls->ea_img);
	}
	if (walls->step_y == -1)
		return (walls->no_img);
	return (walls->so_img);
}

void	draw_wall_door(t_data *data, t_walls *walls)
{
	mlx_texture_t	*texture;
	float			walls_x;

	texture = ft_texture(walls);
	if (walls->side == 0)
		walls_x = data->pos_y + walls->perp_w_dist * walls->ray_dir_y;
	else
		walls_x = data->pos_x + walls->perp_w_dist * walls->ray_dir_x;
	walls_x -= floor(walls_x);
	walls->tex_x = (int)(walls_x * (float)texture->width);
	get_pixels(texture, data->walls->l_height, data);
}
