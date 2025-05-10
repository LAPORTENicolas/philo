/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:11:58 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/09 21:47:27 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"
#include <pthread.h>

void	printt(t_philo *philo, char *str, char *str1, struct timeval now)
{
	//struct timeval	now;
	char			*str2;
	int				time;

	pthread_mutex_lock(philo->print_mutex);
	//gettimeofday(&now, NULL);
	time = (now.tv_sec - philo->start_time.tv_sec) * 1000;
	time += (now.tv_usec - philo->start_time.tv_usec) / 1000;
	str2 = ft_itoa(time);
	ft_printf("%s %s %s\n", str2, str1, str);
	pthread_mutex_unlock(philo->print_mutex);
	if (str2)
		free(str2);
}

void	print_action(char *str, t_philo *philo, struct timeval timestamp)
{
	char	*str1;

	str1 = ft_itoa(philo->id);
	if (!str1)
		return ;
	pthread_mutex_lock(philo->state_mutex);
	if (*philo->state)
		printt(philo, str, str1, timestamp);
	pthread_mutex_unlock(philo->state_mutex);
	free(str1);
}

void	print_dead(char *str, t_philo *philo)
{
	struct timeval	now;
	char			*str2;
	char			*str3;
	int				time;

	str3 = ft_itoa(philo->id);
	pthread_mutex_lock(philo->print_mutex);
	gettimeofday(&now, NULL);
	time = (now.tv_sec - philo->start_time.tv_sec) * 1000;
	time += (now.tv_usec - philo->start_time.tv_usec) / 1000;
	str2 = ft_itoa(time);
	ft_printf("%s %s %s\n", str2, str3, str);
	pthread_mutex_unlock(philo->print_mutex);
	if (str3)
		free(str3);
	if (str2)
		free(str2);
}
