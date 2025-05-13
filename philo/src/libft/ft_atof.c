/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:43:26 by nlaporte          #+#    #+#             */
/*   Updated: 2024/12/12 21:44:00 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '-')
		return (-1);
	return (1);
}

static int	check_len(char *s)
{
	char	**split;

	split = ft_split(s, '.');
	if (!split || !*split || !split[0] || !split[1])
		return (-1);
	if (ft_strlen(split[1]) > 6 || ft_strlen(split[0]) >= 9)
	{
		free(split[0]);
		free(split[1]);
		free(split[2]);
		free(split);
		return (-1);
	}
	free(split[0]);
	free(split[1]);
	free(split);
	return (0);
}

static	int	check_valide(char *s)
{
	int	dot;
	int	len;

	dot = 0;
	len = 0;
	if (*s == '-')
		s++;
	if (check_len(s) == -1)
		return (-1);
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != '.')
			return (-1);
		if (*s == '.')
			dot++;
		if (dot > 1)
			return (-1);
		s++;
		len++;
	}
	if (dot == 0)
		return (-1);
	return (0);
}

static double	*put_malloc(double val)
{
	double	*atof;

	atof = malloc(sizeof(double));
	if (!val)
		return (NULL);
	*atof = val;
	return (atof);
}

double	*ft_atof(char *s)
{
	double	atof;
	double	i;
	int		len;
	int		sign;

	i = 0;
	len = 0;
	atof = 0;
	if (!s || !*s || check_valide(s) == -1)
		return (NULL);
	sign = get_sign(s);
	if (sign == -1)
		s++;
	i = ft_atoi(s);
	while (*s && *s != '.')
		s++;
	s++;
	len = ft_strlen(s);
	atof += (int)i;
	i = ft_atoi(s);
	while (len-- > 0)
		i /= 10;
	atof += i;
	return (put_malloc(atof * sign));
}
