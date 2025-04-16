/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:42:11 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/10 00:42:12 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	unsigned char		cc;

	i = -1;
	cc = (unsigned char)c;
	while ((size_t)++i < n)
		if (*(unsigned char *)(s + i) == cc)
			return ((void *)(s + i));
	return (NULL);
}
