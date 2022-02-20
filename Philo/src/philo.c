/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:10:50 by seyun             #+#    #+#             */
/*   Updated: 2022/02/20 16:30:57 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(int id, int status, t_base *info)
{
	pthread_mutex_lock(&info->message);
	pthread_mutex_lock(&info->protect_die);
	if (!(info->flag_die))
	{	
		if (status == IS_DIE)
			printf("%lld %d is died\n", \
					(get_time_ms() - info->start_time), id + 1);
		else if (status == IS_FORK)
			printf("%lld %d has taken a fork\n", \
					(get_time_ms() - info->start_time), id + 1);
		else if (status == IS_EATING)
			printf("%lld %d is eating\n", \
					(get_time_ms() - info->start_time), id + 1);
		else if (status == IS_SLEEPING)
			printf("%lld %d is sleeping\n", \
					(get_time_ms() - info->start_time), id + 1);
		else if (status == IS_THINKING)
			printf("%lld %d is thinking\n", \
					(get_time_ms() - info->start_time), id + 1);
	}
	pthread_mutex_unlock(&info->protect_die);
	pthread_mutex_unlock(&info->message);
}

void	init_base_info(int ac, char **av, t_base *info)
{
	info->num_philo = ft_atoi(av[1]);
	info->die_ms = ft_atoi(av[2]);
	info->eat_ms = ft_atoi(av[3]);
	info->sleep_ms = ft_atoi(av[4]);
	info->philo = NULL;
	info->fork = NULL;
	info->start_time = 0;
	info->flag_die = 0;
	info->flag_eat = 0;
	if (ac == 6)
	{
		info->num_eat = ft_atoi(av[5]);
		if (!info->num_eat)
			ft_strexit("Base info missing!");
	}
	else
		info->num_eat = -1;
	if (!(info->num_philo) || !(info->die_ms) | !(info->eat_ms) \
			| !(info->sleep_ms))
		ft_strexit("Base info missing!");
}

int	validate_argument(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		ft_strexit("ERROR: Wrong number of Arguments!");
	if (ft_atoi(av[1]) > 199)
		ft_strexit("ERROR: Max num of philo is 200");
	while (*(++av) != 0)
	{	
		if (!ft_only_digit(*av))
			ft_strexit("ERROR: Arguement isnt numeric");
		if (ft_atoi(*av) == -1)
			ft_strexit("ERROR: Wrong argc value!");
	}
	return (0);
}

void	one_philo(t_base *info)
{
	printf("0 1 has taken fork\n");
	usleep(info->die_ms * 1000);
	printf("%d 1 died\n", info->die_ms + 1);
	return ;
}

int	main(int ac, char **av)
{
	t_base	info;

	validate_argument(ac, av);
	init_base_info(ac, av, &info);
	init_pthread(&info);
	if (info.num_philo == 1)
		one_philo(&info);
	if (info.num_philo != 1)
		philo_core(&info);
	if (info.fork)
		free(info.fork);
	if (info.philo)
		free(info.philo);
	return (0);
}
