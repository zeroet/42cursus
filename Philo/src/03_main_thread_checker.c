/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_main_thread_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:58:50 by seyun             #+#    #+#             */
/*   Updated: 2022/01/20 17:04:08 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_count_checker(t_base *info, int *num_eat)
{
	int i;

	i = -1;
	while (info->num_eat != -1 && ++i < info->num_philo)
	{
		pthread_mutex_lock(&(info->eat_cnt));
		if (info->philo[i].eat_count >= info->num_eat)
			(*num_eat) += 1;
		pthread_mutex_unlock(&(info->eat_cnt));
	}
	pthread_mutex_lock(&info->protect_eat);
	if (*num_eat == info->num_philo)
		info->flag_eat = 1;
	pthread_mutex_unlock(&info->protect_eat);
}

void	die_time_checker(t_base *info, int *die)
{
	int i;

	i = 0;
	pthread_mutex_lock(&info->protect_die);
	while (i < info->num_philo && !(info->flag_die))
	{
		pthread_mutex_unlock(&info->protect_die);
		pthread_mutex_lock(&info->philo[i].eat_time);
		if (get_time_ms() - info->philo[i].end_time > info->die_ms)
		{
			pthread_mutex_unlock(&(info->philo[i].eat_time));
			print_message(info->philo[i].id, IS_DIE, info);
			pthread_mutex_lock(&(info->protect_die));
			info->flag_die = 1;
			pthread_mutex_unlock(&(info->protect_die));
			*die = 1;
			return ;
		}
		pthread_mutex_unlock(&(info->philo[i].eat_time));
		pthread_mutex_lock(&(info->protect_die));
		i++;
	}
	pthread_mutex_unlock(&info->protect_die);
}
	

void	main_thread(t_base *info)
{
	int i;
	int	num_eat;
	int	die;

	i = 0;
	die = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_lock(&(info->philo[i].eat_time));
		info->philo[i].end_time = get_time_ms();
		pthread_mutex_unlock(&(info->philo[i].eat_time));
		i++;
	}
	while(!(info->flag_eat))
	{
		num_eat = 0;
		die_time_checker(info, &die);
		if (die)
			break ;
		eat_count_checker(info, &num_eat);
	}
}

void	free_thread(t_base *info)
{
	int i;

	i = 0;
	while (i < info->num_philo)
	{
		pthread_join(info->philo[i].thread_id, NULL);
		pthread_mutex_destroy(&(info->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&info->philo->eat_time);
	pthread_mutex_destroy(&(info->philo->time));
	pthread_mutex_destroy(&(info->message));
	pthread_mutex_destroy(&info->protect_die);
	pthread_mutex_destroy(&info->protect_eat);
	pthread_mutex_destroy(&info->eat_cnt);
}

void	philo_core(t_base *info)
{
	if (!create_pthread(info))
		return ;
	main_thread(info);
	free_thread(info);
	if (!(info->flag_die))
		printf("All philosophers have eaten!\n");
}
