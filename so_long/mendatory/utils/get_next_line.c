/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 06:03:11 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/09 20:41:45 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_get_buffer_size(int fd, char *next_line)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(next_line), NULL);
	buffer[0] = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0 || read_bytes == -1)
			break ;
		buffer[read_bytes] = 0;
		next_line = ft_strjoin(next_line, buffer);
	}
	return (free(buffer), next_line);
}

char	*ft_new_line(char *line)
{
	char	*next_line;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	next_line = malloc(ft_strlen(line) - i + 1);
	if (!next_line)
		return (free(line), NULL);
	ft_strlcpy(next_line, &line[i], ft_strlen(line) - i + 1);
	line[i] = 0;
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*next_line[OPEN_MAX];
	char		*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (fd >= OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (free(next_line[fd]), next_line[fd] = NULL, NULL);
	line = ft_get_buffer_size(fd, next_line[fd]);
	if (!line)
		return (next_line[fd] = NULL, NULL);
	if (!line[0])
		return (free(next_line[fd]), next_line[fd] = NULL, NULL);
	next_line[fd] = ft_new_line(line);
	if (!next_line[fd])
		return (NULL);
	buffer = ft_strdup(line);
	free(line);
	if (!buffer)
		return (free(next_line[fd]), next_line[fd] = NULL, NULL);
	return (buffer);
}
