/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:45:00 by seyun             #+#    #+#             */
/*   Updated: 2021/10/16 14:28:27 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_dlst **stack_a, t_dlst **stack_b)
{
	push_node(stack_a, (pop_node(stack_b)));
	write(1, "pa\n", 3);
}

void	ft_pb(t_dlst **stack_a, t_dlst **stack_b)
{
	push_node(stack_b, (pop_node(stack_a)));
	write(1, "pb\n", 3);
}
