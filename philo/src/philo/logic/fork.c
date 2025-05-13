/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:32:42 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/13 19:35:00 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

void	philo_before(t_philo *philo)
{
	int	tmp;

	tmp = philo->time2eat * 2 - philo->time2sleep;
	if (philo->id == philo->amount && philo->gen == 1)
	{
		if (philo_safe_wait(philo, philo->time2eat * 2) == -1)
			philo_print(philo, "died");
	}
	else if (philo->id == philo->amount && philo->gen == 1)
	{
		if (philo_safe_wait(philo, tmp) == -1)
			philo_print(philo, "died");
	}
}

int	philo_before_fork(t_philo *philo)
{
	int	tmp;

	if (philo->amount == 1)
	{
		philo_print(philo, "has take a fork");
		if (philo_safe_wait(philo, philo->time2die + 1) == -1)
			philo_print(philo, "died");
		return (-1);
	}
	tmp = philo->amount / 2;
	if (philo->gen != 1 && tmp + tmp == philo->amount)
	{
		if (philo_safe_wait(philo, philo->time2eat - philo->time2sleep) == -1)
			philo_print(philo, "died");
		return (-1);
	}
	else if (tmp + tmp < philo->amount)
	{
		philo_before(philo);
		return (-1);
	}
	return (0);
}

int	philo_take_fork(t_philo *philo)
{
	philo_before_fork(philo);
	if (philo->id % 2 == 1)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	if (philo_print(philo, "has take a fork") == -1)
		return (philo_exit_fork(philo, 0));
	if (philo->id % 2 == 1)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	if (philo_eat(philo) != 0)
		return (-1);
	if (philo->id % 2 == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	return (0);
}
