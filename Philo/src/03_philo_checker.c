/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_philo_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:01:20 by seyun             #+#    #+#             */
/*   Updated: 2022/01/19 20:22:13 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(int id, int status, t_base *info)
{
	pthread_mutex_lock(&info->message);
	if (status == IS_DIE)
		printf("%lld %d is died\n", (get_time_ms() - info->start_time), id + 1);
	else if (status == IS_FORK)
		printf("%lld %d has taken a fork\n", (get_time_ms() - info->start_time), id + 1);
	else if (status == IS_EATING)
		printf("%lld %d is eating\n", (get_time_ms() - info->start_time), id + 1);
	else if (status == IS_SLEEPING)
		printf("%lld %d is sleeping\n", (get_time_ms() - info->start_time), id + 1);
	else if (status == IS_THINKING)
		printf("%lld %d is thinking\n", (get_time_ms() - info->start_time), id + 1);
	pthread_mutex_unlock(&info->message);
}

