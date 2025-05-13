/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:25:11 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/13 19:40:45 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static int	philo_check_death(t_philo *philo, struct timeval now)
{
	struct timeval	death;

	death = time_add(philo->last_eat, 0, philo->time2die);
	if (check_time_val(now, death) != 1)
		return (-1);
	return (0);
}

int	philo_safe_wait(t_philo *philo, int ms)
{
	struct timeval	now;
	struct timeval	wait;

	gettimeofday(&now, NULL);
	wait = time_add(now, 0, ms);
	while (check_time_val(now, wait) != -1)
	{
		usleep(100);
		gettimeofday(&now, NULL);
		if (philo_check_death(philo, now))
			return (-1);
	}
	return (0);
}

int	philo_exit_fork(t_philo *philo, int state)
{
	if (philo->id % 2 == 1)
	{
		if (state == 0)
			pthread_mutex_unlock(philo->left_fork);
		else
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
		}
	}
	else
	{
		if (state == 0)
			pthread_mutex_unlock(philo->right_fork);
		else
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
		}
	}
	return (-1);
}

int	philo_eat(t_philo *philo)
{
	if (philo_print(philo, "is eating") == -1)
		return (philo_exit_fork(philo, 1));
	gettimeofday(&philo->last_eat, NULL);
	if (philo_safe_wait(philo, philo->time2eat) == -1)
		return (philo_exit_fork(philo, 1));
	return (0);
}

int	philo_check_eat(t_philo *philo)
{
	int	tmp;

	tmp = philo->time2die - philo->time2eat;
	if (check_time_val2(philo->last_eat, tmp) == 1)
	{
		philo_safe_wait(philo, philo->time2die);
		philo_print(philo, "died");
		return (-1);
	}
	return (0);
}
