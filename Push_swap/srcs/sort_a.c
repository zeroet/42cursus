/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:17:48 by seyun             #+#    #+#             */
/*   Updated: 2021/10/18 23:48:17 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_a(t_dlst **stack_a, t_dlst **stack_b, int len)
{
	if (check_ascend(*stack_a, len))
		return ;
	if ((*stack_a)->next->next->num == ft_max(*stack_a))
	{
		ft_sa(*stack_a);
		return ;
	}
	if ((*stack_a)->num == ft_max(*stack_a))
		ft_sa(*stack_a);
	if ((*stack_a)->num == ft_min(*stack_a))
	{	
		ft_ra(stack_a);
		ft_sa(*stack_a);
		ft_rra(stack_a);
	}
	else
	{
		ft_pb(stack_a, stack_b);
		ft_sa(*stack_a);
		ft_ra(stack_a);
		ft_pa(stack_a, stack_b);
		ft_rra(stack_a);
	}
}

int		except_case_a(t_dlst **stack_a, t_dlst **stack_b, int len)
{
	if (len == 2 && check_descend(*stack_a, len))
		ft_sa(*stack_a);
	if (len == 3 && (stack_size(*stack_a)) == 3)
		only_3(stack_a);
	else if (len == 3)
		sort_3_a(stack_a, stack_b, len);
	if (check_ascend(*stack_a, len))
		return (1);
	return (0);
}

void	A_to_B(t_dlst **stack_a, t_dlst **stack_b, int len)
{
	int pivot;
	t_cnta a;

	init_cnt_a(&a);
	nit_pivot_a(stack_a, len, &a);
	if (except_case_a(stack_a, stack_b, len))
		return ;
	while (len--)
	{
		if ((*stack_a)->num >= a.big_pivot)
		{
			ft_ra(stack_a);
			(a.ra_cnt)++;
		}
		else if ((*stack_b)->num < a.big_pivot)		
		{
			ft_pb(stack_a, stack_b);
			(a.pb_cnt)++;
			if ((*stack_b) >= a.small_pivot)
			{
				ft_rb(stack_b);
				a.rb_cnt++;
			}
		}
	}
	ft_rra_rrb(stack_a, stack_b, &a);
	A_to_B(stack_a, stack_b, a.ra_cnt);
	B_to_A(stack_a, stack_b, a.pb_cnt);
	B_to_A(stack_a, stack_b, (a.pb_cnt - a.rb_cnt));
}

