/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:44:01 by ytak              #+#    #+#             */
/*   Updated: 2021/12/01 14:55:16 by ytak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_argv1(int argc, char *argv[], t_info *all)
{
	(void)argc;
	if (ft_atoi(argv[1]) > 0)
		all->num_philo = ft_atoi(argv[1]);
	if (all->num_philo > 200)
		return (printf("Error! can't have more than 200 philos 👻\n") == 0);
	else if (!ft_atoi(argv[1]))
	{
		printf("Error! range of number of philosophers\n");
		return (0);
	}
	if (ft_atoi(argv[2]) > 0)
		all->time_death = ft_atoi(argv[2]);
	else if (!(ft_atoi(argv[2])))
	{
		printf("Error! range of death time\n");
		return (0);
	}
	if (ft_atoi(argv[3]) > 0)
		all->time_eat = ft_atoi(argv[3]);
	else if (!(ft_atoi(argv[3])))
	{
		printf("Error! range of eat time\n");
		return (0);
	}
	return (1);
}

int	ft_init_argv(int argc, char *argv[], t_info *all)
{
	if (ft_atoi(argv[4]) > 0)
		all->time_sleep = ft_atoi(argv[4]);
	else if (!(ft_atoi(argv[4])))
	{
		printf("Error! range of sleep time\n");
		return (0);
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) > 0)
			all->limit_eattime = ft_atoi(argv[5]);
		else if (!(ft_atoi(argv[5])))
		{
			printf("Error! range of limited eat time\n");
			return (0);
		}
	}
	else
		all->limit_eattime = -1;
	return (1);
}

void	ft_info_init(t_info *all)
{
	all->flag_eat = 0;
	all->flag_die = 0;
	all->time_start = 0;
	all->philo = NULL;
	all->fork = NULL;
}

int	ft_philo_init(t_info *all)
{
	int	i;

	i = 0;
	all->philo = (t_philo *)malloc(sizeof(t_philo) * (all->num_philo));
	if (!(all->philo))
	{
		printf("Error! Malloc philo struct error\n");
		return (0);
	}
	while (i < all->num_philo)
	{
		all->philo[i].id = i;
		all->philo[i].eat_count = 0;
		all->philo[i].left_fork = i;
		all->philo[i].right_fork = (i + 1) % (all->num_philo);
		all->philo[i].last_eat_time = 0;
		all->philo[i].all = all;
		pthread_mutex_init(&(all->philo[i].last_meal), NULL);
		pthread_mutex_init(&(all->philo[i].curr_time), NULL);
		i++;
	}
	return (1);
}
