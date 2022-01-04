/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:11:33 by seyun             #+#    #+#             */
/*   Updated: 2022/01/04 18:26:08 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include "../Libft/libft.h"


typedef struct s_philo
{
	pthread_t	thread_id;
	int			left_fork;
	int			right_fork;
	int			eat_count;
	long long	start_time;
	long long	end_time;
}	t_philo;

typedef struct s_base
{ 
	t_philo *philo;
	int	num_philo;
	int	die_ms;
	int	eat_ms;
	int	sleep_ms;
	int	num_eat;
}	t_base;

int	validate_argument(int ac, char **av);
void	init_pthread(t_base *info);
void	run_philo(t_base *info);


#endif
