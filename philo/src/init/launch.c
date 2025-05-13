/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:24:11 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/13 19:40:14 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

int	launch_one_philo(t_philo *philo, struct timeval now, int type, int sleep)
{
	int	r;

	philo->start_time = now;
	philo->last_eat = now;
	philo->self = (void *)philo;
	philo->type = type;
	r = pthread_create(&philo->thread, NULL, philo_routine, philo->self);
	if (r != 0)
		return (-1);
	usleep(sleep);
	return (0);
}

static void	set_fork(t_env *env, int i, int limit)
{
	pthread_mutex_t	*mutex_fork;
	t_philo			*philo;

	mutex_fork = env->mutex_fork;
	philo = &env->philo[i];
	if (limit == 1)
	{
		philo->left_fork = &mutex_fork[0];
		philo->right_fork = NULL;
	}
	else if (i == 0)
	{
		philo->left_fork = &mutex_fork[0];
		philo->right_fork = &mutex_fork[limit - 1];
	}
	else if (i == limit)
	{
		philo->left_fork = &mutex_fork[limit - 1];
		philo->right_fork = &mutex_fork[limit - 2];
	}
	else
	{
		philo->left_fork = &mutex_fork[i];
		philo->right_fork = &mutex_fork[i - 1];
	}
}

void	prepare_philo(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->philo_amount)
		pthread_mutex_init(&env->mutex_fork[i++], NULL);
	i = -1;
	while (++i < env->philo_amount)
	{
		env->philo[i].id = i + 1;
		env->philo[i].amount = env->philo_amount;
		env->philo[i].time2die = env->time2die;
		env->philo[i].time2eat = env->time2eat;
		env->philo[i].time2sleep = env->time2sleep;
		env->philo[i].state = &env->state;
		env->philo[i].take_fork = &env->take_fork;
		env->philo[i].print_mutex = &env->print_mutex;
		env->philo[i].state_mutex = &env->state_mutex;
		env->philo[i].gen = env->gen;
		env->philo[i].self = (void *)&env->philo[i];
		set_fork(env, i, env->philo_amount);
	}
}

int	launch_philo(t_env *env)
{
	struct timeval	now;
	int				i;

	i = 0;
	gettimeofday(&now, NULL);
	while (i < env->philo_amount)
	{
		if (launch_one_philo(&env->philo[i], now, 0, 0) == -1)
			return (-1);
		i += 2;
	}
	i = 1;
	while (i < env->philo_amount)
	{
		if (launch_one_philo(&env->philo[i], now, 1, 0) == -1)
			return (-1);
		i += 2;
	}
	return (0);
}
