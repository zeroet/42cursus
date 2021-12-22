/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:44:56 by ytak              #+#    #+#             */
/*   Updated: 2021/12/01 17:12:53 by ytak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mutex_init1(t_info *all)
{
	if (pthread_mutex_init(&(all->message), NULL))
		return (printf("Error! initialize mutex error\n") == 0);
	return (1);
}

int	ft_mutex_init(t_info *all)
{
	int	i;

	i = 0;
	all->fork = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * all->num_philo);
	if (!(all->fork))
		return (printf("Error! Malloc fork error\n") == 0);
	while (i < all->num_philo)
	{
		if (pthread_mutex_init(&(all->fork[i]), NULL))
			return (printf("Error! initialize mutex error\n") == 0);
		i++;
	}
	if (pthread_mutex_init(&all->philo->last_meal, NULL))
		return (printf("Error! intialize mutex last_meal error\n") == 0);
	if (pthread_mutex_init(&all->philo->curr_time, NULL))
		return (printf("Error! intialize mutex curr_time error\n") == 0);
	if (pthread_mutex_init(&all->protect_die, NULL))
		return (printf("Error! intialize mutex protect_die error\n") == 0);
	if (pthread_mutex_init(&all->protect_eat, NULL))
		return (printf("Error! intialize mutex protect_eat error\n") == 0);
	if (pthread_mutex_init(&all->eateat_count, NULL))
		return (printf("Error! intialize mutex eateat_counterror\n") == 0);
	ft_mutex_init1(all);
	return (1);
}

int	one_philo(t_info *all)
{
	printf("0 1 has taken a fork\n");
	usleep(all->time_death * 1000);
	printf("%d 1 died\n", all->time_death + 1);
	return (0);
}

int	ft_init_all(int argc, char *argv[], t_info *all)
{
	int	i;

	i = 0;
	ft_info_init(all);
	if (argc != 5 && argc != 6)
		return (printf("Error! Wrong number of arguments 💩\n") == 0);
	while (++i < argc)
		if (ft_atoi(argv[i]) == -1)
			return (printf("Error! Arguments Error 🎃\n") == 0);
	if (!(ft_init_argv(argc, argv, all)))
		return (0);
	if (!(ft_init_argv1(argc, argv, all)))
		return (0);
	if (all->num_philo == 1)
		return (one_philo(all));
	if (!(ft_philo_init(all)))
		return (0);
	if (!(ft_mutex_init(all)))
		return (0);
	return (1);
}
