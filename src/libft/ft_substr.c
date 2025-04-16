/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:40:45 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/10 16:40:46 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	malloc_size(const char *s, unsigned int start, size_t len)
{
	unsigned int	l;

	l = ft_strlen(s);
	if (l < start)
		return (0);
	if (start + len > l)
		return (l - start);
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	size;
	size_t	i;

	size = malloc_size(s, start, len);
	r = malloc(sizeof(char) * (size + 1));
	if (r == NULL)
		return (NULL);
	if (size == 0)
	{
		r[0] = '\0';
		return (r);
	}
	i = -1;
	while (++i < size)
		r[i] = s[i + start];
	r[i] = '\0';
	return (r);
}
