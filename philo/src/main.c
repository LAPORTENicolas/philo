/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:59:12 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/12 16:05:47 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philosophers.h"

void	free_env(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->philo_amount)
	{
		pthread_join(env->philo[i].thread, NULL);
		i++;
	}
	free(env->mutex_fork);
	free(env->philo);
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac <= 4)
		return (-1);
	if (get_env(ac, av, &env) == -1)
		return (-1);
	if (launch_philo(&env) == -1)
		return (-1);
	free_env(&env);
	return (0);
}
