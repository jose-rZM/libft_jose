/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:03:37 by jramire2          #+#    #+#             */
/*   Updated: 2024/09/11 13:05:40 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
		{
			sign = -1;
		}
		++nptr;
	}
	while (ft_isdigit(*nptr))
	{
		ret = (ret * 10) + (*nptr - '0');
		++nptr;
	}
	return (ret * sign);
}
