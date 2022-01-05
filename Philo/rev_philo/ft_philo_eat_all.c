/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eat_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:14:44 by ytak              #+#    #+#             */
/*   Updated: 2022/01/05 17:24:39 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_allowed_to_eat(t_philo *philo, int loop_id)
{
	int	i;

	if (philo->all->num_philo % 2 == 0)
		return (1);
	i = 0;
	loop_id %= philo->all->num_philo;
	while (i < philo->all->num_philo / 2)
	{
		if (philo->id == (loop_id + i * 2) % philo->all->num_philo)
			return (1);
		i++;
	}
	return (0);
}

void	ft_eat_sleep(t_philo *philo)
{
	ft_eat2(philo);
	ft_eat3(philo);
	ft_philo_sleep_think(philo);
}

void	ft_allow_eat_sleep_time(t_philo *philo, t_info *all)
{
	ft_philo_printf(philo->id, "is thinking", all);
	precise_sleep(all->time_eat, philo);
}

void	*ft_philo_eat_all0(t_philo *philo, t_info *all)
{
	int	i;

	i = 0;
	while (!(all->flag_die))
	{
		pthread_mutex_unlock(&all->protect_die);
		if (!is_allowed_to_eat(philo, i))
			ft_allow_eat_sleep_time(philo, all);
		else
		{
			ft_eat_sleep(philo);
			i++;
		}
		pthread_mutex_lock(&all->protect_eat);
		if (all->flag_eat == 1)
		{
			pthread_mutex_unlock(&all->protect_eat);
			return (NULL);
		}
		pthread_mutex_unlock(&all->protect_eat);
		i++;
		pthread_mutex_lock(&all->protect_die);
	}
	return (NULL);
}

void	*ft_philo_eat_all(void *philo_ptr)
{
	t_philo	*philo;
	t_info	*all;

	philo = (t_philo *)philo_ptr;
	all = philo->all;
	if (all->num_philo % 2 == 0)
	{
		if (philo->id % 2 == 1)
		{
			ft_philo_printf(philo->id, "is thinking", all);
			precise_sleep(all->time_eat / 1.3333, philo);
		}
	}
	pthread_mutex_lock(&all->protect_die);
	ft_philo_eat_all0(philo, all);
	pthread_mutex_unlock(&all->protect_die);
	return (NULL);
}
