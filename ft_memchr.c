/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:55:28 by jramire2          #+#    #+#             */
/*   Updated: 2024/09/18 10:48:38 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ps;

	ps = (const unsigned char *)s;
	while (n > 0 && *ps != (unsigned char)c)
	{
		++ps;
		--n;
	}
	if (n == 0)
		return (NULL);
	return ((void *)ps);
}
