/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:14:03 by jramire2          #+#    #+#             */
/*   Updated: 2024/09/18 10:57:08 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	pdest = dest;
	psrc = src;
	while (n > 0)
	{
		*pdest = *psrc;
		++pdest;
		++psrc;
		--n;
	}
	return (dest);
}
