/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:17:07 by ytak              #+#    #+#             */
/*   Updated: 2022/01/19 21:04:03 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_thread(t_info *all)
{
	int	i;

	i = -1;
	all->time_start = ft_get_time();
	while (++i < all->num_philo)
	{
		//all->time_start = ft_get_time();
		if (pthread_create(&(all->philo[i].thread_id),
				NULL, &ft_philo_eat_all, (void *)&(all->philo[i])))
		{
			printf("Error! create thread\n");
			return (0);
		}
	}
	return (1);
}

void	ft_free_thread(t_info *all)
{
	int	i;

	i = 0;
	while (i < all->num_philo)
	{
		pthread_join(all->philo[i].thread_id, NULL);
		pthread_mutex_destroy(&(all->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(all->philo->last_meal));
	pthread_mutex_destroy(&(all->philo->curr_time));
	pthread_mutex_destroy(&(all->message));
	pthread_mutex_destroy(&(all->protect_die));
	pthread_mutex_destroy(&(all->protect_eat));
	pthread_mutex_destroy(&(all->eateat_count));
}

void	ft_thread_all(t_info *all)
{
	if (!(ft_create_thread(all)))
		return ;
	printf("im main\n");
	ft_checker_loop2(all);
	ft_free_thread(all);
	if (!(all->flag_die))
		printf("All philosophers have eaten!🍝\n");
}
