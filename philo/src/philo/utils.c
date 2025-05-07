/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:11:58 by nlaporte          #+#    #+#             */
/*   Updated: 2025/04/15 02:40:34 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"
#include <pthread.h>

char	*get_str(int id, char *str)
{
	char	*id_s;
	char	*tmp;

	id_s = ft_itoa(id);
	tmp = ft_strjoin("	", id_s);
	free(id_s);
	id_s = ft_strjoin(tmp, " ");
	free(tmp);
	tmp = ft_strjoin(id_s, " ");
	free(id_s);
	id_s = ft_strjoin(tmp, str);
	free(tmp);
	return (id_s);
}

void	printt(t_philo *philo, char *str)
{
	struct timeval	now;
	int	time;

	pthread_mutex_lock(philo->print_mutex);
	gettimeofday(&now, NULL);
	time = (now.tv_sec - philo->start_time.tv_sec) * 1000;
	time += (now.tv_usec - philo->start_time.tv_usec) / 1000;
	ft_putnbr_fd(time, 1);
	ft_putendl_fd(str, 1);
	pthread_mutex_unlock(philo->print_mutex);
}

void	print_action(char *str, t_philo *philo)
{
	char *to_print;

	to_print = get_str(philo->id, str);
	pthread_mutex_lock(philo->state_mutex);
	if (*philo->state)
		printt(philo, to_print);
	pthread_mutex_unlock(philo->state_mutex);
	free(to_print);
}

void	print_dead(char *str, t_philo *philo)
{
	char *to_print;

	to_print = get_str(philo->id, str);
	printt(philo, to_print);
	free(to_print);
}
