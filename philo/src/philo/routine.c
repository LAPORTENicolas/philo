/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:14:20 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/09 22:02:37 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"

void	wait_philo(t_philo *philo, int ms)
{
	struct timeval	now;
	struct timeval	wait;

	gettimeofday(&now, NULL);
	wait = time_add(now, 0, ms);
	while (check_time_val(now, wait) != -1)
	{
		usleep(200);
		gettimeofday(&now, NULL);
		if (philo_check_death(philo, 0))
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

long	diff_timeval(struct timeval start, struct timeval end)
{
	long	diff_sec;
	long	diff_usec;

	diff_usec = end.tv_usec - start.tv_usec;
	diff_sec = end.tv_sec - start.tv_sec;
	return (diff_sec * 1000000 + diff_usec);
}

int	philo_eat(t_philo *philo)
{
	struct timeval	now;

	if (philo->left_fork == NULL || philo->right_fork == NULL)
	{
		gettimeofday(&now, NULL);
		print_action("has taken a fork", philo, now);
		philo_check_death(philo, philo->time2die);
		return (-1);
	}
	pthread_mutex_lock(philo->left_fork);
	gettimeofday(&now, NULL);
	print_action("has taken a fork", philo, now);
	if (philo_check_death(philo, 0) == -1)
		return (-1);
	pthread_mutex_lock(philo->right_fork);
	if (philo_check_death(philo, 3) == -1)
		return (-1);
	gettimeofday(&philo->last_eat, NULL);
	print_action("is eating", philo, philo->last_eat);
	wait_philo(philo, philo->time2eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

void	*philo_routine(void *ptr)
{
	struct timeval	now;
	t_philo			*philo;
	int				i;

	i = 0;
	philo = (t_philo *)ptr;
	while (check_if_end(philo) != 1 && (philo->gen == -1 || i++ < philo->gen))
	{
		if (philo_eat(philo) == -1)
			break ;
		philo_check_death(philo, 0);
		if (check_if_end(philo))
			break ;
		gettimeofday(&now, NULL);
		print_action("is sleeping", philo, now);
		wait_philo(philo, philo->time2sleep);
		philo_check_death(philo, 0);
		if (check_if_end(philo))
			break ;
		gettimeofday(&now, NULL);
		print_action("is thinking", philo, now);
		philo_check_death(philo, (philo->time2eat - philo->time2sleep));
		if (check_if_end(philo))
			break ;
	}
	return (NULL);
}
