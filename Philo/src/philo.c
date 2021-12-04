/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:10:50 by seyun             #+#    #+#             */
/*   Updated: 2021/12/05 00:45:41 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_argument(int ac, char **av)
{
	int	i;
	int	argv[4];

	i = 0;
	if (ac != 5)
		ft_strexit("ERROR: Not Given Five Arguments!");
	while (*(++av) != 0)
	{	
		if (!ft_only_digit(*av))
			ft_strexit("ERROR: Arguement isnt numeric");
		argv[i] = ft_atoi(*av);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	validate_argument(ac, av);
	return (0);
}
