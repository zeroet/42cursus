/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 22:42:14 by seyun             #+#    #+#             */
/*   Updated: 2021/10/16 22:47:46 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	A_to_B(t_dlst **stack_a, t_dlst **stack_b, int len)
{
	int pivot;
	int i;
	int ra_cnt;
	int pb_cnt;

	pivot = set_pivot(*stack_a, len);
	ra_cnt = 0;
	pb_cnt = 0;
	while (i < len)
	{
		if ((*stack)->num > pivot)
		{
			ft_ra(stack_a);
			ra_cnt++;
		}
		else
		{	
			ft_pb(stack_a, stack_b);
			pb_cnt++;
		}
	i = 0;
	while (i < ra_cnt)
		ft_rra(stack_a);
	A_to_B(stack_a, stack_b, ra_cnt);
	B_to_A(stack_a, stack_b, pb_cnt);
}
