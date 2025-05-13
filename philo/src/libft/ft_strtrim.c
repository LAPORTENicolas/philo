/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:06:32 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/10 18:06:33 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inside(const char c, const char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	size_t	s_s;
	size_t	i;

	i = 0;
	if (s == NULL || set == NULL)
		return (ft_strndup("", 0));
	while (s[i] && is_inside(s[i], set) == 1)
		i++;
	if (i == ft_strlen(s))
		return (ft_strndup("", 0));
	s_s = ft_strlen(&s[i]);
	while (is_inside(s[s_s + i - 1], set) == 1)
		s_s--;
	return (ft_strndup(&s[i], s_s));
}
