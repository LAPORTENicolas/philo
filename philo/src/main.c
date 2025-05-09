/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:00:12 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/08 23:43:16 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philosophers.h"

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
	env = get_env(ac, av);
	launch_philo(&env);
	free_env(&env);
	return (0);
}
