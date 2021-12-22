/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:11:33 by seyun             #+#    #+#             */
/*   Updated: 2021/12/22 15:34:43 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include "../Libft/libft.h"

typedef struct s_info
{
	pthread_t *philo;
}	t_info;


int	validate_argument(int ac, char **av);

#endif
