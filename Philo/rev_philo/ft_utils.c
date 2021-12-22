/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:00:56 by ytak              #+#    #+#             */
/*   Updated: 2021/12/22 15:38:58 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	long long	nbr;
	int			i;

	nbr = 0;
	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (i > 10 || str[i] < '0' || str[i] > '9')
			return (-1);
		nbr = nbr * 10 + (str[i] - '0');
		if (nbr > 2147483647)
			return (-1);
		++i;
	}
	if (nbr == 0)
		return (-1);
	return ((int)nbr);
}

void	ft_philo_printf(int id, char *str, t_info *all)
{
	pthread_mutex_lock(&(all->message));
	pthread_mutex_lock(&all->protect_die);
	if (!(all->flag_die))
		printf("%lld %d %s\n", ft_get_time() - all->time_start, id + 1, str);
	pthread_mutex_unlock(&all->protect_die);
	pthread_mutex_unlock(&(all->message));
}
