/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 22:42:14 by seyun             #+#    #+#             */
/*   Updated: 2021/10/17 02:01:00 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	A_to_B(t_dlst **stack_a, t_dlst **stack_b, int len)
{
	int pivot;
	t_cnta a;
	int i;

	pivot = set_pivot(*stack_a, len);
	init_cnt_a(&a);
	if (!len)
		return ;
	while (len--)
	{
		if ((*stack_a)->num > pivot && ++(a.ra_cnt))
			ft_ra(stack_a);
		else
		{	
			ft_pb(stack_a, stack_b);
			(a.pb_cnt)++;
		}
	}
	i = 0;
	while (i < a.ra_cnt)
	{
		ft_rra(stack_a);
		i++;
	}
	A_to_B(stack_a, stack_b, a.ra_cnt);
	B_to_A(stack_a, stack_b, a.pb_cnt);
}

void	B_to_A(t_dlst **stack_a, t_dlst **stack_b, int len)
{
	int pivot;
	int i;

	pivot = set_pivot(*stack_b, len);
	init_cnt_b(&b);
	i = 0;
	if (!len)
		return ;
	while (len--)
	{
		if ((*stack_b)->num < pivot && ++(b.ra_cnt))
			ft_ra(stack_a);
		else
		{	
			ft_pb(stack_a, stack_b);
			(b.pa_cnt)++;
		}
	}
	i = 0;
	while (i < b.rb_cnt)
	{
		ft_rrb(stack_b);
		i++;
	}
	A_to_B(stack_a, stack_b, b.pa_cnt);
	B_to_A(stack_a, stack_b, b.rb_cnt);
}
