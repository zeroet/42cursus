/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:57:08 by seyun             #+#    #+#             */
/*   Updated: 2021/10/19 22:36:05 by seyun            ###   ########.fr       */
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

typedef struct s_cnt_a
{
	int ra_cnt;
	int rb_cnt;
	int pb_cnt;
	int big_pivot;
}	t_cnta;

typedef struct s_cnt_b
{
	int ra_cnt;
	int rb_cnt;
	int pa_cnt;
	int small_pivot;
}	t_cntb;

/******** main *********/

void	only_3(t_dlst **stack);

/************* checker **********/

int		check_ascend(t_dlst *lst, int len);
int		check_descend(t_dlst *lst, int len);
int		check_duplicates(t_dlst *lst);
int		stack_size(t_dlst *lst);


/********* descend_stack **********/

void	descend_to_ascend(t_dlst **stack_a, t_dlst **stack_b, int len);

/************ math **********/

int		ft_min(t_dlst *lst);
int		ft_max(t_dlst *lst);

/********** stack_utiles ********/

void	dlst_clear(t_dlst *lst);
void	init_stack(t_dlst **lst, t_dlst *node);
t_dlst *creat_node(int num);
void	push_node(t_dlst **lst, t_dlst *node);
t_dlst	*pop_node(t_dlst **stack);


/*********** globe utiles ********/

void	ft_error(void);
int	ft_atoi(char *str);
void	free_all(t_dlst **stack_a, t_dlst **stack_b);


/********** ra ******/

void	ft_ra(t_dlst **stack_a);
void	ft_rb(t_dlst **stack_b);
void	ft_rr(t_dlst **stack_a, t_dlst **stack_b);

/********** rra *********/

void	ft_rra(t_dlst **stack_a);
void	ft_rrb(t_dlst **stack_b);
void	ft_rrr(t_dlst **stack_a, t_dlst **stack_b);

/********* sa ******/

void	ft_sa(t_dlst *lst);
void	ft_sb(t_dlst *lst);
void	ft_ss(t_dlst *stack_a, t_dlst *stack_b);

/********** pa ***********/

void	ft_pa(t_dlst **stack_a, t_dlst **stack_b);
void	ft_pb(t_dlst **stack_a, t_dlst **stack_b);

/************* pivot **********/

int		set_pivot(t_dlst *stack, int len);
int		*set_table(t_dlst *stack, int len);
int		init_big_pivot(t_dlst *stack, int len);
int		init_small_pivot(t_dlst *stack, int len);


/************* init_functions ******/

void	init_cnt_a(t_cnta *a);
void	init_cnt_b(t_cntb *b);
void	init_pivot_a(t_dlst **lst, int len, t_cnta *a);
void	init_pivot_b(t_dlst **lst, int len, t_cntb *b);


/********** Sort *********/

void	A_to_B(t_dlst **stack_a, t_dlst **stack_b, int len);
void	B_to_A(t_dlst **stack_a, t_dlst **stack_b, int len);

#endif
