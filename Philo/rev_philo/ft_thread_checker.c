/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:14:35 by ytak              #+#    #+#             */
/*   Updated: 2022/01/19 21:12:58 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_checker_all_eat(t_info *all, int *num_eat)
{
	int	i;

	i = -1;
	while (all->limit_eattime != -1 && ++i < all->num_philo)
	{
		pthread_mutex_lock(&(all->eateat_count));
		if (all->philo[i].eat_count >= all->limit_eattime)
			(*num_eat) += 1;
		pthread_mutex_unlock(&(all->eateat_count));
	}
	pthread_mutex_lock(&(all->protect_eat));
	if (*num_eat == all->num_philo)
		all->flag_eat = 1;
	pthread_mutex_unlock(&(all->protect_eat));
}

void	ft_checker_loop0(t_info *all, int *break_val)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&all->protect_die);
	while (i < all->num_philo && !(all->flag_die))
	{
		pthread_mutex_unlock(&all->protect_die);
		pthread_mutex_lock(&(all->philo[i].last_meal));
		if (ft_get_time() - all->philo[i].last_eat_time > all->time_death)
		{
			pthread_mutex_unlock(&(all->philo[i].last_meal));
			ft_philo_printf(all->philo[i].id, "died", all);
			pthread_mutex_lock(&all->protect_die);
			all->flag_die = 1;
			pthread_mutex_unlock(&all->protect_die);
			*break_val = 1;
			return ;
		}
		pthread_mutex_unlock(&(all->philo[i].last_meal));
		pthread_mutex_lock(&all->protect_die);
		i++;
	}
	pthread_mutex_unlock(&all->protect_die);
}

void	ft_checker_loop1(t_info *all)
{
	int	num_eat;
	int	break_val;

	break_val = 0;
	while (!(all->flag_eat))
	{
		num_eat = 0;
		ft_checker_loop0(all, &break_val);
		if (break_val)
			break ;
		ft_checker_all_eat(all, &num_eat);
	}
}

void	ft_checker_loop2(t_info *all)
{
	int	i;

	i = -1;
	while (++i < all->num_philo)
	{
		pthread_mutex_lock(&(all->philo[i].last_meal));
		all->philo[i].last_eat_time = ft_get_time();
		pthread_mutex_unlock(&(all->philo[i].last_meal));
	}
	ft_checker_loop1(all);
}
