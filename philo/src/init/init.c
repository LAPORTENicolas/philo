/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:17:48 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/13 19:35:11 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

static int	get_amount_gen(int ac, char **av, t_env *env)
{
	env->gen = -1;
	if (ac >= 6)
	{
		if (ft_atoi(av[5]) <= 0)
			return (1);
		else
			env->gen = ft_atoi(av[5]);
	}
	env->state = 1;
	return (0);
}

int	get_env(int ac, char **av, t_env *env)
{
	env->philo_amount = ft_atoi(av[1]);
	env->time2die = ft_atoi(av[2]);
	env->time2eat = ft_atoi(av[3]);
	env->time2sleep = ft_atoi(av[4]);
	if (env->time2die < 0 || env->time2eat < 0 || env->philo_amount < 0)
		return (-1);
	if (env->time2sleep < 0 || env->philo_amount > 1000)
		return (-1);
	if (get_amount_gen(ac, av, env))
		return (-1);
	env->mutex_fork = malloc(sizeof(pthread_mutex_t) * env->philo_amount);
	if (!env->mutex_fork)
		return (-1);
	env->philo = malloc(sizeof(t_philo) * env->philo_amount);
	if (!env->philo)
	{
		free(env->mutex_fork);
		return (-1);
	}
	pthread_mutex_init(&env->print_mutex, NULL);
	pthread_mutex_init(&env->state_mutex, NULL);
	pthread_mutex_init(&env->take_fork, NULL);
	prepare_philo(env);
	return (0);
}
