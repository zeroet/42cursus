/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:06:17 by ytak              #+#    #+#             */
/*   Updated: 2022/01/19 18:33:56 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat2(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	pthread_mutex_lock(&(all->fork[philo->right_fork]));
	ft_philo_printf(philo->id, "has taken a fork", all);
	pthread_mutex_lock(&(all->fork[philo->left_fork]));
	ft_philo_printf(philo->id, "has taken a fork", all);
}

void	ft_eat3(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	ft_philo_printf(philo->id, "is eating", all);
	pthread_mutex_lock(&(philo->last_meal));
	philo->last_eat_time = ft_get_time();
	pthread_mutex_unlock(&(philo->last_meal));
	pthread_mutex_lock(&all->eateat_count);
	philo->eat_count++;
	pthread_mutex_unlock(&all->eateat_count);
	precise_sleep(all->time_eat, philo);
	pthread_mutex_unlock(&(all->fork[philo->left_fork]));
	pthread_mutex_unlock(&(all->fork[philo->right_fork]));
}
