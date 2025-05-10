/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:36:19 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/10 14:39:09 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"

static int	checker(t_philo *philo, int subms, struct timeval now,\
				   struct timeval death)
{
	if (subms != 0)
	{
		death = time_add(philo->last_eat, 0, philo->time2die);
		while (check_time_val(now, death) == 1)
		{
			if (*philo->state == 0)
			{
				pthread_mutex_unlock(philo->state_mutex);
				return (-1);
			}
			pthread_mutex_unlock(philo->state_mutex);
			gettimeofday(&now, NULL);
			usleep(100);
			pthread_mutex_lock(philo->state_mutex);
		}
	}
	if (*philo->state)
		*philo->state = 0;
	pthread_mutex_unlock(philo->state_mutex);
	print_dead("died", philo);
	return (1);
}

int	philo_check_death(t_philo *philo, int subms)
{
	struct timeval	death;
	struct timeval	now;

	death = time_add(philo->last_eat, 0, philo->time2die - subms);
	pthread_mutex_lock(philo->state_mutex);
	gettimeofday(&now, NULL);
	if (check_time_val(now, death) != 1 && *philo->state)
		return (checker(philo, subms, now, death));
	pthread_mutex_unlock(philo->state_mutex);
	return (0);
}

/*
int	philo_check_death(t_philo *philo, int subms)
{
	struct timeval	death;
	struct timeval	now;

	death = time_add(philo->last_eat, 0, philo->time2die - subms);
	pthread_mutex_lock(philo->state_mutex);
	gettimeofday(&now, NULL);
	if (check_time_val(now, death) != 1 && *philo->state)
	{
		if (subms != 0)
		{
			death = time_add(philo->last_eat, 0, philo->time2die);
			while (check_time_val(now, death) == 1)
			{
				if (*philo->state == 0)
				{
					pthread_mutex_unlock(philo->state_mutex);
					return (-1);
				}
				pthread_mutex_unlock(philo->state_mutex);
				gettimeofday(&now, NULL);
				usleep(100);
				pthread_mutex_lock(philo->state_mutex);
			}
		}
		if (*philo->state)
			*philo->state = 0;
		pthread_mutex_unlock(philo->state_mutex);
		print_dead("died", philo);
		return (1);
	}
	pthread_mutex_unlock(philo->state_mutex);
	return (0);
}
*/
