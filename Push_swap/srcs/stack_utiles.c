/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:55:30 by seyun             #+#    #+#             */
/*   Updated: 2021/10/20 22:12:09 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dlst_clear(t_dlst *lst)
{
	t_dlst	*tmp;

	lst->prev->next = NULL;
	while (lst)
	{
		tmp = lst->next;
		free (lst);
		lst = tmp;
	}
}

void	init_stack(t_dlst **lst, t_dlst *node)
{
	if (!lst || !node)
		return ;
	if (*lst == 0)
		*lst = node;
	else
	{
		(*lst)->prev->next = node;
		node->prev = (*lst)->prev;
		(*lst)->prev = node;
		node->next = *lst;
	}
	if (check_duplicates(*lst))
	{
		dlst_clear(*lst);
		ft_error();
	}
}

t_dlst	*creat_node(int num)
{
	t_dlst	*new_node;

	new_node = (t_dlst *)malloc(sizeof(t_dlst));
	if (new_node == NULL)
		return (0);
	new_node->num = num;
	new_node->prev = new_node;
	new_node->next = new_node;
	return (new_node);
}

void	push_node(t_dlst **lst, t_dlst *node)
{
	if (!lst || !node)
		return ;
	if (*lst)
	{
		(*lst)->prev->next = node;
		node->prev = (*lst)->prev;
		(*lst)->prev = node;
		node->next = *lst;
	}
	*lst = node;
}

t_dlst	*pop_node(t_dlst **stack)
{
	t_dlst	*pop;

	if (!stack)
		return (NULL);
	if (!*stack)
		return (NULL);
	pop = *stack;
	if (*stack == (*stack)->next)
		*stack = 0;
	else
	{
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
		*stack = (*stack)->next;
		pop->prev = pop;
		pop->next = pop;
	}
	return (pop);
}
