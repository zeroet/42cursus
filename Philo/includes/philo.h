/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:11:33 by seyun             #+#    #+#             */
/*   Updated: 2022/01/06 20:16:03 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include "../Libft/libft.h"

# define IS_DIE 0
# define IS_FORK 1
# define IS_EATING 2
# define IS_SLEEPING 3
# define IS_THINKING 4
# define IS_DONE 5

typedef struct s_philo
{
	struct s_base	*info;
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	int				flag;
	long long		start_time;
	long long		end_time;
	long long		diff_time;
	pthread_t		thread_id;
	pthread_mutex_t	time;
	pthread_mutex_t sleep;
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
void		*philo_routine(void *philo_ptr);

/********** 01_init_pthread **********/

long long	get_time_ms(void);
void		create_mutex(t_base *info);
void		create_pthread(t_base *info);
void		init_pthread(t_base *info);

/********** 02_philo_acts **********/

int	is_sleep(t_base *info, t_philo *philo);

#endif
