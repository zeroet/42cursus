/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:11:33 by seyun             #+#    #+#             */
/*   Updated: 2022/02/20 19:57:26 by seyun            ###   ########.fr       */
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

typedef struct s_philo
{
	struct s_base	*info;
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long long		curr_time;
	long long		end_time;
	pthread_t		thread_id;
	pthread_mutex_t	time;
	pthread_mutex_t	eat_time;
}					t_philo;

typedef struct s_base
{
	int				num_philo;
	int				die_ms;
	int				eat_ms;
	int				sleep_ms;
	int				num_eat;
	long long		start_time;
	int				flag_die;
	int				flag_eat;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	message;
	pthread_mutex_t	eat_cnt;
	pthread_mutex_t	protect_eat;
	pthread_mutex_t	protect_die;
}					t_base;

/********** phlio main **********/

void		print_message(int id, int status, t_base *info);
int			validate_argument(int ac, char **av);
void		init_base_info(int ac, char **av, t_base *info);

/********** 01_init_pthread **********/

long long	get_time_ms(void);
void		create_info_mutex(t_base *info);
void		create_philo_mutex(t_philo *philo);
int			create_pthread(t_base *info);
void		init_pthread(t_base *info);

/********** 02_philo_acts **********/

void		print_message(int id, int status, t_base *info);
void		*philo_routine(void *philo_ptr);
void		*philo_routine_1(t_philo *philo, t_base *info);
void		is_sleep(long long time, t_philo *philo);
void		is_eat(t_philo *philo, t_base *info, int *loop);

/********** 03_main_thread_checker **********/

void		philo_core(t_base *info);
void		main_thread(t_base *info);
void		die_time_checker(t_base *info, int *die);
void		eat_count_checker(t_base *info, int *num_eat);

#endif
