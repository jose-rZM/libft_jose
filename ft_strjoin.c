/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:20:54 by jramire2          #+#    #+#             */
/*   Updated: 2024/09/16 15:32:45 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joined;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!joined)
	{
		return (NULL);
	}
	ft_memmove(joined, s1, s1_len);
	ft_memmove(joined + s1_len, s2, s2_len);
	return (joined);
}
