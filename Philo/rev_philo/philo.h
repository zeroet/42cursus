/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:02:10 by ytak              #+#    #+#             */
/*   Updated: 2022/01/06 19:37:35 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct s_info	*all;
	int				id;
	int				left_fork;
	int				right_fork;
	long long		last_eat_time;
	long long		now_time;
	int				eat_count;
	pthread_t		thread_id;
	pthread_mutex_t	last_meal;
	pthread_mutex_t	curr_time;
}				t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				limit_eattime;
	int				flag_eat;
	int				flag_die;
	long long		time_start;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	message;
	pthread_mutex_t	eateat_count;
	pthread_mutex_t	protect_die;
	pthread_mutex_t	protect_eat;
}				t_info;

//main.c
int			main(int argc, char *argv[]);

//thread.c
void		ft_checker_all_eat(t_info *all, int *num_eat);
void		ft_checker_loop0(t_info *all, int *break_val);
void		ft_checker_loop1(t_info *all);
void		ft_checker_loop2(t_info *all);

//create_thread.c
int			ft_create_thread(t_info *all);
void		ft_free_thread(t_info *all);
void		ft_thread_all(t_info *all);

//ft_philo_eat.c
void		ft_eat2(t_philo	*philo);
void		ft_eat3(t_philo *philo);
void		*ft_philo_eat_all(void *philo_ptr);

//ft_philo_eat_all.c
void		ft_eat_sleep(t_philo *philo);
void		ft_allow_eat_sleep_time(t_philo *philo, t_info *all);
void		*ft_philo_eat_all0(t_philo *philo, t_info *all);
void		*ft_philo_eat_all(void *philo_ptr);

//ft_sleep.c
long long	ft_get_time(void);
void		ft_philo_sleep_think(t_philo *philo);
void		precise_sleep(long long time, t_philo *philo);

//ft_struct_init.c
int			ft_init_argv1(int argc, char *argv[], t_info *all);
int			ft_init_argv(int argc, char *argv[], t_info *all);
void		ft_info_init(t_info *all);
int			ft_philo_init(t_info *all);

//ft_mutex_init.c
int			ft_mutex_init1(t_info *all);
int			ft_mutex_init(t_info *all);
int			ft_init_all(int argc, char *argv[], t_info *all);

//ft_utils.c
int			ft_atoi(char *str);
void		ft_philo_printf(int id, char *str, t_info *all);

#endif
