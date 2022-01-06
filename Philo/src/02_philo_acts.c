/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_philo_acts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:59:45 by seyun             #+#    #+#             */
/*   Updated: 2022/01/06 20:50:31 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_sleep(t_base *info, t_philo *philo)
{
	int i;

	i = info->num_philo;
	philo->start_time = get_time_ms();
	//printf("id == %d\n", philo->id);
	/*
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(philo->time));
		printf("%lld %d is sleeping\n", (get_time_ms() - philo->start_time), philo->id);
		pthread_mutex_unlock(&(philo->time));
	}
	*/
	return (0);
}
