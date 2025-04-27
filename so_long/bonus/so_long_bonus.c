/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:44:44 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/08 19:40:11 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_map_characters(char *lines_map, t_game *game, int *e, int *p)
{
	int	i;

	i = 0;
	while (lines_map[i])
	{
		if (lines_map[i] != '0' && lines_map[i] != '1' && lines_map[i] != 'P' \
		&& lines_map[i] != 'E' && lines_map[i] != 'C' && lines_map[i] != 'A' \
		&& lines_map[i] != '\n')
		{
			ft_putstr_fd("ERROR CHAR IN MAP!!!!\n", 2);
			return (0);
		}
		if (lines_map[i] == 'P')
			(*p)++;
		else if (lines_map[i] == 'E')
			(*e)++;
		else if (lines_map[i] == 'A')
			game->a++;
		else if (lines_map[i] == 'C')
			game->total_c++;
		i++;
	}
	return (1);
}

void	fc(char	*lines_map, char *line, int fd, char **map)
{
	free(lines_map);
	if (line)
		free(line);
	close(fd);
	if (map)
		free_map(map);
}

int	check_map(t_game *game, char *path_map, int p, int e)
{
	int		fd;
	char	*line;
	char	*lm;

	game->a = 0;
	fd = open(path_map, O_RDONLY, 0777);
	if (fd == -1)
		return (ft_putstr_fd("Error: file not open!\n", 2), 0);
	lm = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "\n", 1) == 0)
			return (fc(lm, line, fd, NULL), ft_putstr_fd("EMPTY L\n", 2), 0);
		lm = ft_strjoin(lm, line);
		free(line);
		line = get_next_line(fd);
	}
	game->map = ft_split(lm, '\n');
	if (!game->map)
		return (fc(lm, NULL, fd, NULL), ft_putstr_fd("MAP NOT FOUND!\n", 2), 0);
	if (!check_map_characters(lm, game, &p, &e) \
	|| p != 1 || e != 1 || game->a < 1 || game->total_c < 1)
		return (fc(lm, NULL, fd, game->map), ft_putstr_fd("+\n", 2), 0);
	return (fc(lm, NULL, fd, NULL), 1);
}

char	**check_map_border(char **map)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	height = 0;
	width = ft_strlen(map[0]);
	while (map[height] != NULL)
		height++;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (ft_putstr_fd("ERROR: Border is not closed!\n", 2), NULL);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (ft_putstr_fd("ERROR: Border is not closed!\n", 2), NULL);
		i++;
	}
	return (map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.x = -1;
	game.y = -1;
	game.count_c = 0;
	game.total_c = 0;
	game.count_move = 0;
	if (argc != 2)
		return (0);
	if (!init_game(&game, argv[1]))
		return (1);
	draw_map(&game);
	handle_mlx_hooks(&game);
	mlx_loop(game.mlx);
}
