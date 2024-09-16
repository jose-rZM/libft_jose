/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:21:09 by jramire2          #+#    #+#             */
/*   Updated: 2024/09/16 16:49:01 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	words;

	if (s == NULL)
		return (0);
	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			++words;
			while (*s && *s != c)
			{
				++s;
			}
		}
		else
		{
			++s;
		}
	}
	return (words);
}

static void	skip_delims(char const **s, char c)
{
	while (**s && **s == c)
		(*s)++;
}

static size_t	substr_len(char const *start, char c)
{
	size_t	length;

	length = 0;
	while (*start && *start != c)
	{
		++start;
		++length;
	}
	return (length);
}

static void	free_array(char **vector, size_t from)
{
	while (--from > 0)
		free(vector[from]);
	free(vector);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**splitted;
	size_t	i;
	size_t	len;

	words = count_words(s, c);
	splitted = ft_calloc(words + 1, sizeof(char *));
	if (!splitted)
		return (NULL);
	i = 0;
	while (i < words)
	{
		skip_delims(&s, c);
		len = substr_len(s, c);
		splitted[i] = ft_substr(s, 0, len);
		if (!splitted[i])
		{
			free_array(splitted, i);
			return (NULL);
		}
		s += len;
		++i;
	}
	splitted[i] = NULL;
	return (splitted);
}
