/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:05:18 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/13 19:31:36 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

static int	philo_check_death_print(t_philo *philo, struct timeval now)
{
	struct timeval	death;

	death = time_add(philo->last_eat, 0, philo->time2die);
	if (check_time_val(now, death) != 1 && *philo->state)
		return (-1);
	return (0);
}

int	philo_print_2(t_philo *philo, long int time, struct timeval now)
{
	gettimeofday(&now, NULL);
	if (philo_check_death_print(philo, now) == -1)
	{
		*philo->state = 0;
		pthread_mutex_unlock(philo->state_mutex);
		printf("%li %i died\n", time, philo->id);
		pthread_mutex_unlock(philo->print_mutex);
		return (-1);
	}
	else if (*philo->state == 0)
	{
		pthread_mutex_unlock(philo->state_mutex);
		pthread_mutex_unlock(philo->print_mutex);
		return (-1);
	}
	return (0);
}

int	philo_print(t_philo *philo, char *str)
{
	struct timeval	now;
	long int		time;

	pthread_mutex_lock(philo->state_mutex);
	pthread_mutex_lock(philo->print_mutex);
	gettimeofday(&now, NULL);
	time = (now.tv_sec - philo->start_time.tv_sec) * 1000;
	time += (now.tv_usec - philo->start_time.tv_usec) / 1000;
	if (philo_print_2(philo, time, now) == -1)
		return (-1);
	printf("%li %i %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->print_mutex);
	pthread_mutex_unlock(philo->state_mutex);
	return (0);
}
