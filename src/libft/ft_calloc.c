/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 03:43:14 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/10 03:43:15 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*r;

	if (elementCount != 0 && elementSize > SIZE_MAX / elementCount)
		return (NULL);
	r = malloc(elementCount * elementSize);
	if (r == NULL)
		return (NULL);
	return (ft_memset(r, 0, elementCount * elementSize));
}
