/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:11:33 by seyun             #+#    #+#             */
/*   Updated: 2022/01/05 18:28:47 by seyun            ###   ########.fr       */
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
	struct s_base	*info;
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long long		start_time;
	long long		end_time;
	pthread_t		thread_id;
}					t_philo;

typedef struct s_base
{ 
	t_philo			*philo;
	int				num_philo;
	int				die_ms;
	int				eat_ms;
	int				sleep_ms;
	int				num_eat;
	pthread_mutex_t *fork;
}					t_base;

/********** phlio main **********/

int			validate_argument(int ac, char **av);
void		init_base_info(int ac, char **av, t_base *info);

/********** 01_init_pthread **********/

long long	get_time_ms(void);
void		create_mutex(t_base *info);
void		create_pthread(t_base *info);
void		init_pthread(t_base *info);

/********** 02_philo_routine **********/

void		*philo_routine(void *philo_ptr);

#endif
