/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:17:38 by nlaporte          #+#    #+#             */
/*   Updated: 2024/08/29 18:35:03 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*val;

	i = 0;
	val = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (val == NULL)
		return (NULL);
	while (src[i])
	{
		val[i] = src[i];
		i++;
	}
	val[i] = '\0';
	return (val);
}
