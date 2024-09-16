/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:36:29 by jramire2          #+#    #+#             */
/*   Updated: 2024/09/16 16:19:33 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int	contains(char const *s, char c)
{
	while (*s && *s != c)
		++s;
	return (*s == c);
}

size_t	count_leftmost_ocurrences(char const *s1, char const *set)
{
	size_t	cnt;

	cnt = 0;
	while (*s1 && contains(set, *s1))
	{
		++cnt;
		++s1;
	}
	return (cnt);
}

size_t	count_rightmost_ocurrences(char const *s1, char const *set)
{
	size_t	cnt;
	size_t	len;
	int		i;

	cnt = 0;
	len = ft_strlen(s1);
	i = len - 1;
	while (i >= 0 && s1[i] && contains(set, s1[i]))
	{
		++cnt;
		--i;
	}
	return (cnt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	left;
	size_t	right;
	char	*trimmed;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	left = count_leftmost_ocurrences(s1, set);
	right = count_rightmost_ocurrences(s1, set);
	if (left == s1_len || right == s1_len)
		return (ft_calloc(1, sizeof(char)));
	trimmed = ft_calloc(s1_len - left - right + 1, sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, s1 + left, s1_len - left - right);
	return (trimmed);
}
