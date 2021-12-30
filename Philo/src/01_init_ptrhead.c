/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init_ptrhead.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:37:56 by seyun             #+#    #+#             */
/*   Updated: 2021/12/30 17:44:09 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_pthread(t_base *info)
{
	int i;

	base->philo = (t_philo *)malloc(sizeof(t_phlio) * base->num_philo);
	if (!(base_philo))
		strexit("ERROR: Malloc fail! (t_philo)");
	i = 0;
	while (i < base->num_philo)
	{
		base->philo[i].thread_id = (pthread_t *)malloc(sizeof(pthread_t));
		if (!(base->philo[i].thread_id))
			ft_strexit("ERROR: Malloc fail! (pthread_t)");
		base->philo[i].left_fork = i;
		base->philo[i].right_fork = (i + 1) % (base->num_philo);
		base->eat_count = 0;
		base->start_time = 0;
		base->end_time = 0;
		
		i++;
	}	
}
