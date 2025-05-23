/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:41:24 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/07 19:28:10 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_words(const char *str, char c)
{
	size_t	i;
	size_t	words;
	int		is_word;

	i = 0;
	words = 0;
	is_word = 0;
	while (str[i])
	{
		if (str[i] != c && !is_word)
		{
			words++;
			is_word = 1;
		}
		else if (str[i] == c)
			is_word = 0;
		i++;
	}
	return (words);
}

static char	*extract_word(const char *str, char c, size_t index)
{
	size_t	i;

	i = 0;
	while (str[index + i] && str[index + i] != c)
		i++;
	return (ft_substr(str, index, i));
}

static int	ft_free(char **p, size_t j)
{
	if (!p[j - 1])
	{
		while (j--)
			free(p[j]);
		free(p);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**p;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	p = ft_calloc(count_words(s, c) + 1, 8);
	if (!p)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			p[j++] = extract_word(s, c, i);
			if (!ft_free(p, j))
				return (NULL);
			i += ft_strlen(p[j - 1]);
		}
		else
			i++;
	}
	return (p);
}
