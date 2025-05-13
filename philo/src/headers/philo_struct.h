/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:14:44 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/10 14:30:45 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include <bits/pthreadtypes.h>
# include <time.h>

typedef struct s_philo
{
	int				amount;
	void			*self;
	int				*state;
	int				id;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				gen;
	int				type;
	pthread_mutex_t	*take_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*state_mutex;
	struct timeval	start_time;
	struct timeval	last_eat;
	pthread_t		thread;
}					t_philo;

typedef struct s_env
{
	int				philo_amount;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				state;
	int				gen;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
	pthread_mutex_t	take_fork;
	pthread_mutex_t	*mutex_fork;
	t_philo			*philo;
}					t_env;

#endif
