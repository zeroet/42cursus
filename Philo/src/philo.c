/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:10:50 by seyun             #+#    #+#             */
/*   Updated: 2021/12/22 16:04:21 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_argument(int ac, char **av)
{
	if (ac != 5)
		ft_strexit("ERROR: Not Given Five Arguments!");
	if (ft_atoi(av[1]) > 199)
		ft_strexit("ERROR: philo 200");
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
	//t_info all;

	validate_argument(ac, av);
	return (0);
}
