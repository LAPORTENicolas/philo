/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:27:07 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/10 02:27:10 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	needle_len = ft_strlen(needle);
	i = 0;
	if (needle_len == 0)
		return ((char *)haystack);
	if (needle_len > len)
		return (NULL);
	while (i <= len - needle_len && haystack[i])
	{
		if (haystack[i] == needle[0])
			if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
				return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
