/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:21:22 by jramire2          #+#    #+#             */
/*   Updated: 2024/09/16 15:19:07 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
	{
		return (NULL);
	}
	if (start <= s_len)
	{
		ft_memcpy(sub, s + start, len);
	}
	return ((char *)sub);
}
