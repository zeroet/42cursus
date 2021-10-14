/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:57:08 by seyun             #+#    #+#             */
/*   Updated: 2021/10/14 22:48:52 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_dlst
{
	int num;
	struct s_dlst *prev;
	struct s_dlst *next;
}			t_dlst;

/******** main *********/

void	only_3(t_dlst **stack);

/************* checker **********/

int		check_ascend(t_dlst *lst, int len);
int		check_descend(t_dlst *lst, int len);
int		check_duplicates(t_dlst *lst);

/************ stack_utiles ******/

t_dlst *creat_node(int num);
void	init_stack(t_dlst **lst, t_dlst *node);
void	dlst_clear(t_dlst *lst);

/************ math **********/

int		ft_min(t_dlst *lst);
int		ft_max(t_dlst *lst);

/********** stack_utiles ********/

void	dlst_clear(t_dlst *lst);
void	init_stack(t_dlst **lst, t_dlst *node);
t_dlst *creat_node(int num);

/*********** globe utiles ********/

void	ft_error(void);
int	ft_atoi(char *str);

/********** ra ******/

void	ft_ra(t_dlst **lst);
void	ft_rb(t_dlst **lst);
void	ft_rr(t_dlst **stack_a, t_dlst **stack_b);

/********* sa ******/

void	ft_sa(t_dlst *lst);
void	ft_sb(t_dlst *lst);
void	ft_ss(t_dlst *stack_a, t_dlst *stack_b);

/********* push ******/

void	push_node(t_dlst **lst, t_dlst *node);
void	ft_pa(t_dlst **stack_b, t_dlst **stack_a);

#endif
