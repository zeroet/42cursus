/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:46:48 by seyun             #+#    #+#             */
/*   Updated: 2022/01/05 18:32:34 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *philo_ptr)
{
	t_base	*info;
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	info = philo->info;
	printf("%lld %d has taken a fork\n", philo->start_time, philo->id);
	return (NULL);
}
