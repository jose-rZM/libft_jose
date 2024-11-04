/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:09:24 by jramire2          #+#    #+#             */
/*   Updated: 2024/10/31 14:18:18 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_length(int n)
{
	size_t	length;

	if (n == 0)
		return (1);
	length = 0;
	if (n < 0)
		length = 1;
	while (n != 0)
	{
		++length;
		n /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	size_t			length;
	char			*str;
	unsigned int	magnitude;

	length = num_length(n);
	str = ft_calloc(1 + length, sizeof(char));
	if (!str)
		return (NULL);
	magnitude = n;
	if (n < 0)
	{
		magnitude = -n;
		str[0] = '-';
	}
	if (magnitude == 0)
		str[0] = '0';
	while (magnitude != 0)
	{
		str[length - 1] = (magnitude % 10) + '0';
		magnitude /= 10;
		length--;
	}
	return (str);
}
