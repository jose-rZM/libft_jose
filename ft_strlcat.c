/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:00:25 by jramire2          #+#    #+#             */
/*   Updated: 2024/09/18 12:01:24 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst && dsize == 0)
	{
		return (ft_strlen(src));
	}
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dsize <= dst_len)
	{
		return (dsize + ft_strlen(src));
	}
	i = 0;
	while (src[i] != '\0' && dst_len + i < dsize - 1)
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
