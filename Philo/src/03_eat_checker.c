/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_eat_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:59:53 by seyun             #+#    #+#             */
/*   Updated: 2022/01/18 22:21:11 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_checker(t_philo *philo, t_base *info)
{
	if (info->num_philo % 2 == 0)
		if (philo->id % 2 == 0)
			return (1);
	return (0);
}

int	is_done(t_philo *philo, t_base *info)
{
	if (info->num_eat == philo->eat_count)
		return (1);
	return (0);
}
