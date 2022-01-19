/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init_ptrhead.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:37:56 by seyun             #+#    #+#             */
/*   Updated: 2022/01/19 21:16:43 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_ms(void)
{
	struct timeval my_time;

	gettimeofday(&my_time, NULL);
	return ((my_time.tv_sec * 1000) + (my_time.tv_usec / 1000));
}

void	create_info_mutex(t_base *info)
{
	int i;

	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!info->fork)
		ft_strexit("ERROR: Mutex init error!");
	i = 0;
	while (i < info->num_philo)
	{
		if(pthread_mutex_init(&(info->fork[i]), NULL) != 0)
			ft_strexit("ERROR: Mutex init error(fork)");
		i++;
	}
	if (pthread_mutex_init(&(info->message), NULL) != 0)
		ft_strexit("ERROR: Mutex init error(message)");
	if (pthread_mutex_init(&(info->eat_cnt), NULL) != 0)
		ft_strexit("ERROR: Mutex init error(eat_cnt)");
	if (pthread_mutex_init(&(info->protect_die), NULL) != 0)
		ft_strexit("ERROR: Mutex init error(protect_die)");
	if (pthread_mutex_init(&(info->protect_eat), NULL) != 0)
		ft_strexit("ERROR: Mutex init error(protect_eat)");
}

void	create_philo_mutex(t_philo *philo)
{
	if (pthread_mutex_init(&(philo->time), NULL) != 0)
		ft_strexit("ERROR: Mutex init error(time)");
	if (pthread_mutex_init(&(philo->eat_time), NULL) != 0)
		ft_strexit("ERROR: Mutex init error(eat_time)");
}

void	init_pthread(t_base *info)
{
	int i;

	info->philo = (t_philo *)malloc(sizeof(t_philo) * (info->num_philo));
	if (!info->philo)
		ft_strexit("ERROR: Malloc fail! (t_philo)");
	i = 0;
	while (i < info->num_philo)
	{
		info->philo[i].id = i;
		info->philo[i].left_fork = i;
		info->philo[i].right_fork = (i + 1) % (info->num_philo);
		info->philo[i].curr_time = 0;
		info->philo[i].eat_count = 0;
		info->philo[i].info = info;
		create_philo_mutex(&info->philo[i]);
		i++;
	}
	create_info_mutex(info);
}

int	create_pthread(t_base *info)
{
	int i;

	i = 0;
	info->start_time = get_time_ms();
	while (i < info->num_philo)
	{
		if(pthread_create(&(info->philo[i].thread_id), NULL, &philo_routine, (void *)&(info->philo[i])))
		{	
			ft_strexit("ERROR: Fail to create pthread!");
			return (0);
		}
		i++;
	}
	return (1);
}
