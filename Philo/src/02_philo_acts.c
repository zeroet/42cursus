/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_philo_acts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:59:45 by seyun             #+#    #+#             */
/*   Updated: 2022/01/18 22:21:12 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(int id, int status, t_base *info)
{
	pthread_mutex_lock(&info->message);
	if (status == IS_DIE)
		printf("%lld %d is died\n", (get_time_ms() - info->start_time), id + 1);
	else if (status == IS_FORK)
		printf("%lld %d has taken a fork\n", (get_time_ms() - info->start_time), id + 1);
	else if (status == IS_EATING)
		printf("%lld %d is eating\n", (get_time_ms() - info->start_time), id + 1);
	else if (status == IS_SLEEPING)
		printf("%lld %d is sleeping\n", (get_time_ms() - info->start_time), id + 1);
	else if (status == IS_THINKING)
		printf("%lld %d is thinking\n", (get_time_ms() - info->start_time), id + 1);
	pthread_mutex_unlock(&info->message);
}

void	is_sleep(long long time, t_philo *philo)
{
	pthread_mutex_lock(&philo->time);
	philo->curr_time = get_time_ms();
	pthread_mutex_unlock(&philo->time);
	while ((get_time_ms() - philo->end_time) < time)
	{
		if (philo->info->num_philo <= 50)
			usleep(100);
		else
			usleep(1000);
	}
}

void	is_think(t_philo *philo, t_base *info)
{
	print_message(philo->id, IS_THINKING, info);
}

void	is_eat(t_philo *philo, t_base *info)
{
	pthread_mutex_lock(&(info->fork[philo->left_fork]));
	print_message(philo->id, IS_FORK, info);
	pthread_mutex_lock(&(info->fork[philo->right_fork]));
	print_message(philo->id, IS_FORK, info);
	print_message(philo->id, IS_EATING, info);
	pthread_mutex_lock(&(philo->eat_time));
	philo->end_time = get_time_ms();
	pthread_mutex_unlock(&(philo->eat_time));
	pthread_mutex_lock(&(philo->eat_cnt));
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->eat_cnt));
	is_sleep(info->eat_ms, philo);
	pthread_mutex_unlock(&(info->fork[philo->left_fork]));
	pthread_mutex_unlock(&(info->fork[philo->right_fork]));
	is_think(philo, info);
}

void	*philo_routine(void *philo_ptr)
{
	t_philo *philo;
	t_base *info;

	philo = (t_philo *)philo_ptr;
	info = philo->info;
	if (info->num_philo % 2 == 0)
	{
		if (philo->id % 2 == 1)
		{	
			print_message(philo->id, IS_THINKING, info);
			is_sleep(info->eat_ms / 1.3333, philo);
		}
	}
	while (is_done(philo, info) != 1) 
	{
		if (eat_checker(philo, info) == 1)
			is_eat(philo, info);
		else
		{	
			is_sleep(info->eat_ms, philo);
			is_think(philo, info);
		}
	}
	return (NULL);
}
