/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:14:25 by jramire2          #+#    #+#             */
/*   Updated: 2024/09/15 21:38:34 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dsize && src[i] != '\0')
	{
		dst[i] = src[i];
		++i;
	}
	if (i < dsize)
		dst[i] = '\0';
	while (src[i] != '\0')
	{
		++i;
	}
	return (i);
}
