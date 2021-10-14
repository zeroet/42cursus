/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:40:58 by seyun             #+#    #+#             */
/*   Updated: 2021/10/14 22:02:22 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_node(t_dlst **lst, t_dlst *node)
{
	if (!lst || !node)
		return ;
	if (*lst == 0)
		*lst = node;
	else
	{
		node = (*lst)->prev->next;
		(*lst)->prev = node->prev;
		*lst = node->next;
		node = (*lst)->prev;
		node = *lst;
	}
}

void	ft_pa(t_dlst **stack_b, t_dlst **stack_a)
{
	t_dlst *tmp;
	int	num;
	t_dlst *new_node;

	if (!stack_b || !stack_a)
		return ;
	tmp = *stack_a;
	num = (*stack_a)->num;
	(*stack_a)->prev = (*stack_a)->next->prev;
	(*stack_a)->next = (*stack_a)->prev->next;
	*stack_a = (*stack_a)->next;
	free(tmp);
	tmp = NULL;
	new_node = creat_node(num);
	push_node(stack_a, new_node);
	write(1, "pa\n", 3);
}
