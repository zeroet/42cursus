/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:10:50 by seyun             #+#    #+#             */
/*   Updated: 2021/12/04 22:44:25 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_argument(char **av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (!ft_only_digit(av[i]))
			ft_strexit("ERROR: give only digit arguments!");
		i++;
	}
	if (i != 5)
		ft_strexit("ERROR: Give 5 arguments");
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 5)
		exit(0);
	validate_argument(av);
	return (0);
}
