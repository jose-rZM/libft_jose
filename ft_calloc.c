/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:49:07 by jramire2          #+#    #+#             */
/*   Updated: 2024/09/13 20:41:30 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated;
	size_t	total;

	total = nmemb * size;
	if (total == 0)
		return (malloc(0));
	else if (total / nmemb != size)
		return (NULL);
	allocated = malloc(total);
	if (allocated == NULL)
		return (NULL);
	ft_memset(allocated, 0, total);
	return (allocated);
}
