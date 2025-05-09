/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:11:58 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/09 00:03:21 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"
#include <pthread.h>

void	printt(t_philo *philo, char *str)
{
	struct timeval	now;
	int	time;

	pthread_mutex_lock(philo->print_mutex);
	gettimeofday(&now, NULL);
	time = (now.tv_sec - philo->start_time.tv_sec) * 1000;
	time += (now.tv_usec - philo->start_time.tv_usec) / 1000;
  ft_printf("%i %i %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->print_mutex);
}

void	print_action(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->state_mutex);
	if (*philo->state)
		printt(philo, str);
	pthread_mutex_unlock(philo->state_mutex);
}

void	print_dead(char *str, t_philo *philo)
{
	printt(philo, str);
}
