/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:11:48 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/10 17:11:49 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*r;
	size_t	s_s1;
	size_t	s_s2;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s_s1 = ft_strlen(s1);
	s_s2 = ft_strlen(s2);
	if (s_s1 * sizeof(char) > SIZE_MAX - sizeof(char) * (s_s2 + 1))
		return (NULL);
	i = 0;
	r = malloc(sizeof(char) * (s_s1 + s_s2 + 1));
	if (r == NULL)
		return (NULL);
	while (i < s_s1)
		r[i++] = *s1++;
	while (i < s_s1 + s_s2)
		r[i++] = *s2++;
	r[i] = '\0';
	return (r);
}
