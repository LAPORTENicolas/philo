/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:14:20 by nlaporte          #+#    #+#             */
/*   Updated: 2025/04/15 02:37:46 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"
#include <pthread.h>
#include <sys/time.h>

void	wait_philo(t_philo *philo, int ms)
{
	(void)philo;
	struct timeval	now;
	struct timeval	wait;

	gettimeofday(&now, NULL);
	wait = time_add(now, 0, ms);
	while (check_time_val(now, wait) != -1)
	{
		usleep(150);
		gettimeofday(&now, NULL);
		if (philo_check_death(philo))
			return ;
	}
}

int	check_if_end(t_philo *philo)
{
	pthread_mutex_lock(philo->state_mutex);
	if (*philo->state == 0)
	{
		pthread_mutex_unlock(philo->state_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->state_mutex);
	return (0);
}

long diff_timeval(struct timeval start, struct timeval end)
{
	long diff_sec = end.tv_sec - start.tv_sec;
	long diff_usec = end.tv_usec - start.tv_usec;
	return diff_sec * 1000 + (diff_usec / 1000);
}

int	philo_check_death(t_philo *philo)
{
	struct timeval	death;
	struct timeval	now;

	death = time_add(philo->last_eat, 0, philo->time2die);
	pthread_mutex_lock(philo->state_mutex);
	gettimeofday(&now, NULL);
	if (check_time_val(now, death) != 1 && *philo->state)
	{
		*philo->state = 0;
		pthread_mutex_unlock(philo->state_mutex);
		print_dead("is dead", philo);
		return (1);
	}
	pthread_mutex_unlock(philo->state_mutex);
	return (0);
}

void	philo_eat(t_philo *philo)
{
	if (philo->left_fork > philo->right_fork)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	print_action("has taken a fork", philo);
	philo_check_death(philo);
	gettimeofday(&philo->last_eat, NULL);
	print_action("is eating", philo);
	wait_philo(philo, philo->time2eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;
	int	i;

	i = 0;
	philo = (t_philo *)ptr;
	while (check_if_end(philo) != 1 && (philo->gen == -1 ||i++ < philo->gen))
	{
		philo_eat(philo);
		philo_check_death(philo);
		if (check_if_end(philo))
			break ;
		print_action("is sleeping", philo);
		wait_philo(philo, philo->time2sleep);
	
		philo_check_death(philo);
		if (check_if_end(philo))
			break ;
		print_action("is thinking", philo);
		philo_check_death(philo);
	}
	return (NULL);
}
