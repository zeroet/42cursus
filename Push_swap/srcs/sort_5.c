/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:26:32 by seyun             #+#    #+#             */
/*   Updated: 2021/10/20 22:21:06 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_5(t_dlst **stack_a, t_dlst **stack_b, int len)
{
	int	pivot;
	int	i;

	pivot = set_pivot(*stack_a, len);
	while (len--)
	{
		if ((*stack_a)->num > pivot)
		{	
			ft_pb(stack_a, stack_b);
		}
		else
			ft_ra(stack_a);
	}
	if (stack_size(*stack_a) == 3)
		only_3(stack_a);
	if ((*stack_b)->num > (*stack_b)->next->num)
		ft_sb(*stack_b);
	ft_pa(stack_a, stack_b);
	ft_ra(stack_a);
	ft_pa(stack_a, stack_b);
	ft_ra(stack_a);
}
