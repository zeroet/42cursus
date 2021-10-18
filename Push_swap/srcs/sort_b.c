/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:19:06 by seyun             #+#    #+#             */
/*   Updated: 2021/10/18 15:45:00 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_b(t_dlst **stack_a,t_dlst **stack_b, int len)
{
	if ((*stack_b)->next->num == ft_max(*stack_b))
		ft_sb(*stack_b);
	if ((*stack_b)->num == ft_max(*stack_b))
	{
		ft_pa(stack_a, stack_b);
		if ((*stack_b)->num == ft_min(*stack_b))
		{
			ft_sb(*stack_b);
			ft_pa(stack_a, stack_b);
			ft_pa(stack_a, stack_b);
		}
	}
	else
	{
		ft_sb(*stack_b);
		ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
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
	int i;
	t_cntb b;
	int test;

	if (except_case_b(stack_a, stack_b, len))
		return ;
	pivot = set_pivot(*stack_b, len);
	init_cnt_b(&b);
	i = 0;
	if (!len)
		return ;
	while (len--)
	{
		if ((*stack_b)->num >= pivot)
		{
			printf("%d --before rb\n", (*stack_b)->num);
			ft_rb(stack_b);
			b.rb_cnt++;
		}
		else if ((*stack_b)->num < pivot)
		{
			printf("%d --before pa\n", (*stack_b)->num);
			ft_pa(stack_a, stack_b);
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
