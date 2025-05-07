/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:14:48 by nlaporte          #+#    #+#             */
/*   Updated: 2025/04/15 02:17:32 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOFUN_H
#define PHILOFUN_H

#include "philo_struct.h"

// init
t_env	get_env(int ac, char **av);
void	free_env(t_env *env);
void	launch_philo(t_env *env);

// philo
void	*philo_routine(void *ptr);
void	print_action(char *color, t_philo *philo);
void	print_dead(char *str, t_philo *philo);
int		check_if_end(t_philo *philo);
int		philo_check_death(t_philo *philo);

// time
struct timeval	time_add(struct timeval time, int sec, int ms);
int	check_time_val(struct timeval a, struct timeval b);
int	check_time_val2(struct timeval a, int ms);

#endif
