/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:01:39 by jramire2          #+#    #+#             */
/*   Updated: 2024/09/17 13:09:30 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	length;
	char	*mapped;
	size_t	i;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	mapped = ft_calloc(length + 1, sizeof(char));
	if (!mapped)
		return (NULL);
	i = 0;
	while (i < length)
	{
		mapped[i] = f(i, s[i]);
		++i;
	}
	return (mapped);
}
