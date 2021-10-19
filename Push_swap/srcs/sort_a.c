/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:17:48 by seyun             #+#    #+#             */
/*   Updated: 2021/10/19 18:33:47 by seyun            ###   ########.fr       */
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

void	ft_rra_rrb(t_dlst **stack_a, t_dlst **stack_b, t_cnta *a)
{
	int rrr;
	int ra;
	int rb;

	ra = a->ra_cnt;
	rb = a->rb_cnt;
	if (ra >= rb)
	{	
		rrr = rb;
		ra -= rrr;
		while (rrr--)
			ft_rrr(stack_a, stack_b);
		while (ra--)
			ft_rra(stack_a);
	}
	else
	{	
		rrr = ra;
		rb -= rrr;
		while (rrr--)
			ft_rrr(stack_a, stack_b);
		while (rb--)
			ft_rrb(stack_b);
	}
}

void	A_to_B(t_dlst **stack_a, t_dlst **stack_b, int len)
{
	t_cnta a;
	int pivot;
	int i;
	int j;
	int k;

	init_cnt_a(&a);
	init_pivot_a(stack_a, len, &a);
	pivot = set_pivot(*stack_a, len);
	/*
	for(k=0; k<len; k++)
	{
		printf("--test before--yyy stack_a %d\n", (*stack_a)->num);
		*stack_a = (*stack_a)->next;
	}
	for (j =0; j<len; j++)
	{
		printf("--test after--yyy stack_a %d\n", (*stack_a)->num);
		*stack_a = (*stack_a)->next;
	}
	*/
	if (except_case_a(stack_a, stack_b, len))
		return ;
	while (len--)
	{
		if ((*stack_a)->num >= a.big_pivot)
		{
			ft_ra(stack_a);
			(a.ra_cnt)++;
		}
		else if ((*stack_a)->num < a.big_pivot)		
		{
			ft_pb(stack_a, stack_b);
			(a.pb_cnt)++;
			if ((*stack_b)->num >= pivot)
			{
				ft_rb(stack_b);
				(a.rb_cnt)++;
			}
		}
	}
	ft_rra_rrb(stack_a, stack_b, &a);
	/*for (i = 0; i < a.ra_cnt; i++)
	{
		printf("%d -- A - stack a\n", (*stack_a)->num);
		*stack_a = (*stack_a)->next;
	}
	for (j = 0; j < a.pb_cnt; j++)
	{
		printf("%d -- A -- stack b\n", (*stack_b)->num);
		*stack_b = (*stack_b)->next;
	}*/
	printf("AAAAAAAA%d // %d// %d//\n", a.ra_cnt, a.rb_cnt, a.pb_cnt);
	A_to_B(stack_a, stack_b, a.ra_cnt);
	printf("AAAA%d // %d// %d//\n", a.ra_cnt, a.rb_cnt, a.pb_cnt);
	B_to_A(stack_a, stack_b, a.rb_cnt);
	/*
	for (i =0; i < 5; i++)
	{
		printf("%d -- A - stack a\n", (*stack_a)->num);
		*stack_a = (*stack_a)->next;
	}
	for (j = 0; j < (a.pb_cnt - a.rb_cnt); j++)
	{
		printf("%d -- A -- stack b\n", (*stack_b)->num);
		*stack_b = (*stack_b)->next;
	}
	*/
	printf("AA%d // %d// %d//\n", a.ra_cnt, a.rb_cnt, a.pb_cnt);
	B_to_A(stack_a, stack_b, (a.pb_cnt - a.rb_cnt));
}
