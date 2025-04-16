/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:47:43 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/12 18:17:31 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	int				last;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	last = -1;
	while (s[i])
		if ((unsigned char)s[i++] == uc)
			last = i - 1;
	if (last != -1)
		return ((char *)(s + last));
	if ((unsigned char)s[i] == uc)
		return ((char *)(s + i));
	return (NULL);
}
