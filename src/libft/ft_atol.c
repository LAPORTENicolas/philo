/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 03:23:58 by nlaporte          #+#    #+#             */
/*   Updated: 2025/02/10 03:25:08 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	get_num(const char *nptr)
{
	long	i;
	long	r;

	i = 0;
	r = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r *= 10;
		r += (char)nptr[i++] - '0';
	}
	return (r);
}

long	ft_atol(const char *nptr)
{
	long	sign;

	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\f' || *nptr == '\r' \
		|| *nptr == '\t' || *nptr == '\v')
		nptr++;
	sign = 1;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	return (get_num(nptr) * sign);
}
