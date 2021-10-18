/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:19:06 by seyun             #+#    #+#             */
/*   Updated: 2021/10/19 00:06:10 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_b(t_dlst **stack_a,t_dlst **stack_b, int len)
{
	int min;

	min = ft_min(*stack_b);
	if ((*stack_b)->next->num == ft_max(*stack_b))
		ft_sb(*stack_b);
	if ((*stack_b)->num == ft_max(*stack_b))
	{
		ft_pa(stack_a, stack_b);
		if ((*stack_b)->num == ft_min(*stack_b))
			ft_sb(*stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
	}
	else
	{
		ft_pa(stack_a, stack_b);
		ft_sb(*stack_b);
		ft_pa(stack_a, stack_b);
		ft_sa(*stack_a);
		if ((*stack_a)->num != min)
			ft_sa(*stack_a);
	}
}


int		except_case_b(t_dlst **stack_a, t_dlst **stack_b, int len)
{
	if (len == 3)
	{
		sort_3_b(stack_a, stack_b, len);
		return (1);
	}
	if (len == 2 && check_ascend(*stack_b, len))
	{
		ft_sb(*stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
		return (1);
	}
	if (check_descend(*stack_b, len))
	{
		while (len--)
			ft_pa(stack_a, stack_b);
		return (1);
	}
	return (0);
}

void	B_to_A(t_dlst **stack_a, t_dlst **stack_b, int len)
{
	int pivot;
	t_cntb b;

	init_cnt_b(&b);
	pivot = init_pivot(*stack_b, &b);
	if (except_case_b(stack_a, stack_b, len))
		return ;
	while (len--)
	{
		if ((*stack_b)->num < b.small_pivot)
		{
			ft_rb(stack_b);
			b.rb_cnt++;
		}
		else
		{
			ft_pa(stack_a, stack_b);
			(b.pa_cnt)++;
			if ((*stack_b)->num < b.big_pivot)
			{
				ft_ra(stack_b);
				b.ra_cnt++;
			}
		}
	}
	ft_rra_rrb(stack_a, stack_b, &b);
	A_to_B(stack_a, stack_b, b.pa_cnt);
	B_to_A(stack_a, stack_b, b.rb_cnt);
}
