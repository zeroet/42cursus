/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:03:26 by ytak              #+#    #+#             */
/*   Updated: 2021/11/29 19:48:06 by ytak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(void)
{
	struct timeval	my_time;

	gettimeofday(&my_time, NULL);
	return ((my_time.tv_sec * 1000) + (my_time.tv_usec / 1000));
}

void	precise_sleep(long long time, t_philo *philo)
{
	pthread_mutex_lock(&(philo->curr_time));
	philo->now_time = ft_get_time();
	pthread_mutex_unlock(&(philo->curr_time));
	while ((ft_get_time() - philo->now_time) < time)
	{			
		if (philo->all->num_philo <= 50)
			usleep(100);
		else
			usleep(1000);
	}
}

void	ft_philo_sleep_think(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	ft_philo_printf(philo->id, "is sleeping", all);
	precise_sleep(all->time_sleep, philo);
	ft_philo_printf(philo->id, "is thinking", all);
}
