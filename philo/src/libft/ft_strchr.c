/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:47:31 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/09 23:47:31 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((unsigned char)*s && (unsigned char)*s != (unsigned char)c)
		s++;
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
