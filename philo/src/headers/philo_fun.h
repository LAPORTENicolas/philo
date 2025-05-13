/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:14:48 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/13 19:41:16 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FUN_H
# define PHILO_FUN_H

# include "philo_struct.h"

// init
int				get_env(int ac, char **av, t_env *env);
void			prepare_philo(t_env *env);
int				launch_philo(t_env *env);

// philo
void			*philo_routine(void *ptr);
int				philo_take_fork(t_philo *philo);
int				philo_print(t_philo *philo, char *str);
int				philo_safe_wait(t_philo *philo, int ms);
int				philo_exit_fork(t_philo *philo, int state);
int				philo_eat(t_philo *philo);

// time
struct timeval	time_add(struct timeval time, int sec, int ms);
int				check_time_val(struct timeval a, struct timeval b);
int				check_time_val2(struct timeval a, int ms);

#endif
