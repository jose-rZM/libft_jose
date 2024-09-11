/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:07:28 by jramire2          #+#    #+#             */
/*   Updated: 2024/09/11 13:16:29 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ps;

	ps = s;
	while (n > 0)
	{
		*ps = (unsigned char)c;
		++ps;
		--n;
	}
	return (s);
}
