/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:14:20 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/09 22:02:37 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"
#include <pthread.h>
#include <sys/time.h>

void	wait_philo(t_philo *philo, int ms)
{
	struct timeval	now;
	struct timeval	wait;

	gettimeofday(&now, NULL);
	wait = time_add(now, 0, ms);
	while (check_time_val(now, wait) != -1)
	{
		usleep(200);
		gettimeofday(&now, NULL);
		if (philo_check_death(philo, 0))
			return ;
	}
}

int check_if_end(t_philo *philo)
{
	pthread_mutex_lock(philo->state_mutex);
	if (*philo->state == 0)
	{
		pthread_mutex_unlock(philo->state_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->state_mutex);
	return (0);
}

long diff_timeval(struct timeval start, struct timeval end)
{
	long diff_sec = end.tv_sec - start.tv_sec;
	long diff_usec = end.tv_usec - start.tv_usec;
	return (diff_sec * 1000000 + diff_usec);
}

int	philo_check_death(t_philo *philo, int subms)
{
	struct timeval	death;
	struct timeval	now;

	death = time_add(philo->last_eat, 0, philo->time2die - subms);
	pthread_mutex_lock(philo->state_mutex);
	gettimeofday(&now, NULL);
	if (check_time_val(now, death) != 1 && *philo->state)
	{
    if (subms != 0)
    {
	    death = time_add(philo->last_eat, 0, philo->time2die);
      while (check_time_val(now, death) == 1)
      {
        if (*philo->state == 0)
        {
		      pthread_mutex_unlock(philo->state_mutex);
          return (-1);
        }
		    pthread_mutex_unlock(philo->state_mutex);
	      gettimeofday(&now, NULL);
        usleep(100);
		    pthread_mutex_lock(philo->state_mutex);
      }
    }
    if (*philo->state)
		  *philo->state = 0;
		pthread_mutex_unlock(philo->state_mutex);
		print_dead("died", philo);
		return (1);
	}
	pthread_mutex_unlock(philo->state_mutex);
	return (0);
}

int	philo_eat(t_philo *philo)
{
  if (philo->left_fork == NULL || philo->right_fork == NULL)
  {
	  print_action("has taken a fork", philo);
    philo_check_death(philo, philo->time2die);
    return (-1);
  }
  pthread_mutex_lock(philo->left_fork);
  print_action("has taken a fork", philo);
	if (philo_check_death(philo, 0) == -1)
    return (-1);
  pthread_mutex_lock(philo->right_fork);
	if (philo_check_death(philo, 0) == -1)
    return (-1);
	gettimeofday(&philo->last_eat, NULL);
	print_action("is eating", philo);
	wait_philo(philo, philo->time2eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
  return (0);
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;
	int	i;

	i = 0;
	philo = (t_philo *)ptr;
	while (check_if_end(philo) != 1 && (philo->gen == -1 ||i++ < philo->gen))
	{
		if (philo_eat(philo) == -1)
      break;
		philo_check_death(philo, 0);
		if (check_if_end(philo))
			break ;
		print_action("is sleeping", philo);
		wait_philo(philo, philo->time2sleep);
	
		philo_check_death(philo, 0);
		if (check_if_end(philo))
			break ;
		print_action("is thinking", philo);
		philo_check_death(philo, (philo->time2eat - philo->time2sleep));
		if (check_if_end(philo))
			break ;
	}
	return (NULL);
}
