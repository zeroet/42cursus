/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:22:15 by ytak              #+#    #+#             */
/*   Updated: 2021/12/22 15:42:25 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_info	all;

	if (!ft_init_all(argc, argv, &all))
		return (0);
	ft_thread_all(&all);
	if (all.fork)
		free(all.fork);
	if (all.philo)
		free(all.philo);
	return (0);
}	
