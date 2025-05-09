/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:17:48 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/09 12:57:25 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philosophers.h"
#include <pthread.h>
#include <stdlib.h>

void	debug(t_env *env)
{
	int i;
	
	i = 0;
	while (i < env->philo_amount)
	{
		printf("id: %i\n", env->philo[i].id);
		printf("time2die: %i\n", env->philo[i].time2die);
		printf("time2eat: %i\n", env->philo[i].time2eat);
		printf("time2sleep: %i\n", env->philo[i].time2sleep);
		i++;
	}
}

void	prepare_philo(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->philo_amount)
		pthread_mutex_init(&env->mutex_fork[i++], NULL);
	i = 0;
	while (i < env->philo_amount)
	{
		env->philo[i].id = i + 1;
		env->philo[i].time2die = env->time2die;
		env->philo[i].time2eat = env->time2eat;
		env->philo[i].time2sleep = env->time2sleep;
		env->philo[i].state = &env->state;
		env->philo[i].left_fork = &env->mutex_fork[i];
		env->philo[i].print_mutex = &env->print_mutex;
		env->philo[i].state_mutex = &env->state_mutex;
		env->philo[i].gen = env->gen;
		if (i + 1 != env->philo_amount)
			env->philo[i].right_fork = &env->mutex_fork[i + 1];
    else if (1 == env->philo_amount)
			env->philo[i].right_fork = NULL;
		else
			env->philo[i].right_fork = &env->mutex_fork[0];
		env->philo[i].self = (void *)&env->philo[i];
		i++;
	}
}

void  abort_philo(t_env *env, int thread_amount)
{
  int   i;

  i = 0;
  while (i < thread_amount)
  {
    pthread_join(env->philo[i].thread, NULL);
    i++;
  }
  free(env->mutex_fork);
  free(env->philo);
  exit(EXIT_FAILURE);
}

void	launch_philo(t_env *env)
{
	struct timeval	now;
	int	i;

	i = 0;
	gettimeofday(&now, NULL);
	while (i < env->philo_amount)
	{
		env->philo[i].start_time = now;
		env->philo[i].last_eat = now;
		env->philo[i].self = (void *)&env->philo[i];
		if (pthread_create(&env->philo[i].thread, NULL, philo_routine, env->philo[i].self) != 0)
      abort_philo(env, i);
    usleep(20);
		i++;
	}
}

int	get_env(int ac, char **av, t_env *env)
{
	env->philo_amount = ft_atoi(av[1]);
	env->time2die = ft_atoi(av[2]);
	env->time2eat = ft_atoi(av[3]);
	env->time2sleep = ft_atoi(av[4]);
  if (env->time2die < 0 || env->time2eat < 0 || \
    env->time2sleep < 0 || env->philo_amount < 0)
    return(-1);
	env->gen = -1;
	if (ac >= 6)
		env->gen = ft_atoi(av[5]);
	env->state = 1;
	env->mutex_fork = malloc(sizeof(pthread_mutex_t) * env->philo_amount);
  if (!env->mutex_fork)
    return(-1);
	env->philo = malloc(sizeof(t_philo) * env->philo_amount);
  if (!env->philo)
  {
    free(env->mutex_fork);
    return(-1);
  }
	pthread_mutex_init(&env->print_mutex, NULL);
	pthread_mutex_init(&env->state_mutex, NULL);
  prepare_philo(env);
	return (0);
}

/*
t_env	get_env(int ac, char **av)
{
	t_env	env;

	env.philo_amount = ft_atoi(av[1]);
	env.time2die = ft_atoi(av[2]);
	env.time2eat = ft_atoi(av[3]);
	env.time2sleep = ft_atoi(av[4]);
  if (env.time2die < 0 || env.time2eat < 0 || \
    env.time2sleep < 0 || env.philo_amount < 0)
    exit(EXIT_FAILURE);
	env.gen = -1;
	if (ac >= 6)
		env.gen = ft_atoi(av[5]);
	env.state = 1;
	env.mutex_fork = malloc(sizeof(pthread_mutex_t) * env.philo_amount);
  if (!env.mutex_fork)
    exit(EXIT_FAILURE);
	env.philo = malloc(sizeof(t_philo) * env.philo_amount);
  if (!env.philo)
  {
    free(env.mutex_fork);
    exit(EXIT_FAILURE);
  }
	pthread_mutex_init(&env.print_mutex, NULL);
	pthread_mutex_init(&env.state_mutex, NULL);
	prepare_philo(&env);
	return (env);
}
*/
