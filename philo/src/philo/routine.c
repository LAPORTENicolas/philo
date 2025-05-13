/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:14:45 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/13 19:31:28 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

int	philo_check_death(t_philo *philo, struct timeval now)
{
	struct timeval	death;

	death = time_add(philo->last_eat, 0, philo->time2die);
	if (check_time_val(now, death) != 1)
		return (-1);
	return (0);
}

static int	philo_safe_wait2(t_philo *philo, int ms)
{
	struct timeval	now;
	struct timeval	wait;

	gettimeofday(&now, NULL);
	wait = time_add(now, 0, ms);
	while (check_time_val(now, wait) != -1)
	{
		usleep(1000);
		gettimeofday(&now, NULL);
		(void)philo;
	}
	return (0);
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)ptr;
	i = philo->gen;
	philo->gen = 0;
	while (i == -1 || i > philo->gen++)
	{
		if (philo_take_fork(philo) == -1)
			break ;
		philo_print(philo, "is sleeping");
		if (philo_safe_wait2(philo, philo->time2sleep) == -1)
			break ;
		philo_print(philo, "is thinking");
	}
	return (NULL);
}
