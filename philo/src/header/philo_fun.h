/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:14:48 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/10 14:28:46 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FUN_H
# define PHILO_FUN_H

# include "philo_struct.h"

// init
void			free_env(t_env *env);
int				get_env(int ac, char **av, t_env *env);
int				launch_philo(t_env *env);

// philo
void			*philo_routine(void *ptr);
void			print_action(char *color, t_philo *philo, struct timeval timestamp);
void			print_dead(char *str, t_philo *philo);
int				check_if_end(t_philo *philo);
int				philo_check_death(t_philo *philo, int subms);
int				philo_check_death(t_philo *philo, int subms);

// time
struct timeval	time_add(struct timeval time, int sec, int ms);
int				check_time_val(struct timeval a, struct timeval b);
int				check_time_val2(struct timeval a, int ms);

#endif
