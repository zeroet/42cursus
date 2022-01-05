/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init_ptrhead.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:37:56 by seyun             #+#    #+#             */
/*   Updated: 2022/01/05 18:30:32 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_ms(void)
{
	struct timeval my_time;

	gettimeofday(&my_time, NULL);
	return ((my_time.tv_sec * 1000) + (my_time.tv_usec / 1000));
}

void	create_mutex(t_base *info)
{
	int i;

	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!info->fork)
		ft_strexit("ERROR: Mutex init error!");
	i = 0;
	while (i < info->num_philo)
	{
		if(pthread_mutex_init(&(info->fork[i]), NULL) != 0)
			ft_strexit("ERROR: Mutex init error!");
		i++;
	}
}
void	create_pthread(t_base *info)
{
	int i;

	i = 0;
	while (i < info->num_philo)
	{
		if(pthread_create(&info->philo[i].thread_id, NULL, \
					&philo_routine, (void *)&(info->philo[i])))
			ft_strexit("ERROR: Fail to create pthread!");
		i++;
	}
}

void	init_pthread(t_base *info)
{
	int i;

	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	if (!info->philo)
		ft_strexit("ERROR: Malloc fail! (t_philo)");
	i = 0;
	while (i < info->num_philo)
	{
		info->philo[i].id = i;
		info->philo[i].left_fork = i;
		info->philo[i].right_fork = (i + 1) % (info->num_philo);
		info->philo[i].start_time = 0;
		info->philo[i].end_time = 0;
		info->philo[i].eat_count = 0;
		i++;
	}
	create_pthread(info);
	create_mutex(info);
}
