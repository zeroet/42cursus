/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_philo_acts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:59:45 by seyun             #+#    #+#             */
/*   Updated: 2022/01/20 17:16:27 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int eat_checker(t_philo *philo, int loop)
{
	int i;

	if (philo->info->num_philo % 2 == 0)
	return (1);
	i = 0;
	loop %= philo->info->num_philo;
	while (i < philo->info->num_philo / 2)
	{
		if (philo->id == (loop + i * 2) % philo->info->num_philo)
			return (1);
		i++;
	}
	return (0);
}

void	is_sleep(long long time, t_philo *philo)
{
	pthread_mutex_lock(&philo->time);
	philo->curr_time = get_time_ms();
	pthread_mutex_unlock(&philo->time);
	while ((get_time_ms() - philo->curr_time) < time)
	{
		if (philo->info->num_philo <= 50)
			usleep(100);
		else
			usleep(1000);
	}
}

void	is_eat(t_philo *philo, t_base *info)
{
	pthread_mutex_lock(&(info->fork[philo->right_fork]));
	print_message(philo->id, IS_FORK, info);
	pthread_mutex_lock(&(info->fork[philo->left_fork]));
	print_message(philo->id, IS_FORK, info);
	print_message(philo->id, IS_EATING, info);
	pthread_mutex_lock(&(philo->eat_time));
	philo->end_time = get_time_ms();
	pthread_mutex_unlock(&(philo->eat_time));
	pthread_mutex_lock(&(info->eat_cnt));
	philo->eat_count++;
	pthread_mutex_unlock(&(info->eat_cnt));
	is_sleep(info->eat_ms, philo);
	pthread_mutex_unlock(&(info->fork[philo->left_fork]));
	pthread_mutex_unlock(&(info->fork[philo->right_fork]));
	print_message(philo->id, IS_SLEEPING, info);
	is_sleep(info->sleep_ms, philo);
	print_message(philo->id, IS_THINKING, info);
}

void	*philo_routine_1(t_philo *philo, t_base *info)
{
	int loop;

	loop = 0;
	while (!info->flag_die) 
	{
		pthread_mutex_unlock(&info->protect_die);
		if (!eat_checker(philo, loop))
		{
			print_message(philo->id, IS_THINKING, info);
			is_sleep(info->eat_ms, philo);
		}
		else
		{	
			is_eat(philo, info);
			loop++;
		}
		pthread_mutex_lock(&info->protect_eat);
		if (info->flag_eat == 1)
		{
			pthread_mutex_unlock(&info->protect_eat);
			return (NULL);
		}
		pthread_mutex_unlock(&info->protect_eat);
		loop++;
		pthread_mutex_lock(&info->protect_die);
	}
	return (NULL);
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
	pthread_mutex_lock(&info->protect_die);
	philo_routine_1(philo, info);
	pthread_mutex_unlock(&info->protect_die);
	return (NULL);
}
