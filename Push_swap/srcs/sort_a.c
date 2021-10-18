/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:17:48 by seyun             #+#    #+#             */
/*   Updated: 2021/10/18 17:16:55 by seyun            ###   ########.fr       */
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
	int i;

	if (except_case_a(stack_a, stack_b, len))
		return ;
	pivot = set_pivot(*stack_a, len);
	init_cnt_a(&a);
	if (!len)
		return ;
	while (len--)
	{
		if ((*stack_a)->num >= pivot)
		{
			ft_ra(stack_a);
			(a.ra_cnt)++;
		}
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

