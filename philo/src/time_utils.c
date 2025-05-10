/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:33:06 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/08 21:18:36 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philosophers.h"

struct timeval	time_add(struct timeval time, int sec, int ms)
{
	if (sec > 0)
		time.tv_sec += sec;
	if ((time.tv_usec) + (ms * 1000) >= 1000000)
	{
		time.tv_sec++;
		time.tv_usec = (time.tv_usec + (ms * 1000)) - 1000000;
	}
	else
		time.tv_usec += ms * 1000;
	return (time);
}

int	check_time_val(struct timeval a, struct timeval b)
{
	if (a.tv_sec > b.tv_sec)
		return (-1);
	else if (b.tv_sec > a.tv_sec)
		return (1);
	if (a.tv_usec > b.tv_usec)
		return (-1);
	else if (b.tv_usec > a.tv_usec)
		return (1);
	return (0);
}

int	check_time_val2(struct timeval a, int ms)
{
	struct timeval	b;

	gettimeofday(&b, NULL);
	b = time_add(b, 0, ms);
	if (a.tv_sec > b.tv_sec)
		return (-1);
	else if (b.tv_sec > a.tv_sec)
		return (1);
	if (a.tv_usec > b.tv_usec)
		return (-1);
	else if (b.tv_usec > a.tv_usec)
		return (1);
	return (0);
}
