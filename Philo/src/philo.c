/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:10:50 by seyun             #+#    #+#             */
/*   Updated: 2022/01/04 18:15:29 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_base_info(int ac, char **av, t_base *info)
{
	info->num_philo = ft_atoi(av[1]);
	info->die_ms = ft_atoi(av[2]);
	info->eat_ms = ft_atoi(av[3]);
	info->sleep_ms = ft_atoi(av[4]);
	if (ac == 6)
	{
		info->num_eat = ft_atoi(av[5]);
		if (!info->num_eat)
			ft_strexit("Base info missing!");
	}
	else
		info->num_eat = -1;
	if (!(info->num_philo) || !(info->die_ms) | !(info->eat_ms) \
			| !(info->sleep_ms))
		ft_strexit("Base info missing!");
}

int	validate_argument(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		ft_strexit("ERROR: Wrong number of Arguments!");
	if (ft_atoi(av[1]) > 200)
		ft_strexit("ERROR: Max num of philo is 200");
	while (*(++av) != 0)
	{	
		if (!ft_only_digit(*av))
			ft_strexit("ERROR: Arguement isnt numeric");
		if (ft_atoi(*av) == -1)
			ft_strexit("ERROR: Wrong argc value!");
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_base info;

	validate_argument(ac, av);
	init_base_info(ac, av, &info);
	init_pthread(&info);
	create_pthread(&info);
	return (0);
}
