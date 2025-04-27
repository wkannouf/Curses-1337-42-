/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:24:09 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/15 03:24:43 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	if (!dst || !src)
		return (0);
	while (src[i] && i < n - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = malloc(ft_strlen(s1) + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	return (p);
}

char	*ft_strjoin(char *line, const char *buffer)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (line == NULL && buffer == NULL)
		return (NULL);
	if (line == NULL)
		return (ft_strdup(buffer));
	if (buffer == NULL)
		return (ft_strdup(line));
	i = 0;
	j = 0;
	p = malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (p == NULL)
		return (free(line), NULL);
	while (line[i])
		p[j++] = line[i++];
	i = 0;
	while (buffer[i])
		p[j++] = buffer[i++];
	p[j] = 0;
	return (free(line), p);
}

char	*ft_strchr(char *line, int c)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == (char)c)
			return (&((char *)line)[i]);
		i++;
	}
	if (line[i] == (char)c)
		return (&((char *)line)[i]);
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n -1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
