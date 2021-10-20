/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descend_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:10:28 by seyun             #+#    #+#             */
/*   Updated: 2021/10/20 22:20:52 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	descend_to_ascend(t_dlst **stack_a, t_dlst **stack_b, int len)
{
	int	cnt;

	cnt = len;
	if (!stack_a || !stack_b)
		return ;
	if (len == 2)
	{
		ft_sa(*stack_a);
		return ;
	}
	while (--len)
		ft_pb(stack_a, stack_b);
	while (--cnt)
	{
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
	}
}
