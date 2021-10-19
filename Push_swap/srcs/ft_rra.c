/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:43:03 by seyun             #+#    #+#             */
/*   Updated: 2021/10/19 12:03:12 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_dlst **stack_a)
{
	if (!*stack_a || !stack_a)
		return ;
	*stack_a = (*stack_a)->prev;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_dlst **stack_b)
{
	if (!*stack_b || !stack_b)
		return ;
	*stack_b = (*stack_b)->prev;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_dlst **stack_a, t_dlst **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	*stack_a = (*stack_a)->prev;
	if (!stack_b || !*stack_b)
		return ;
	*stack_b = (*stack_b)->prev;
	write(1, "rrr\n", 4);
}
