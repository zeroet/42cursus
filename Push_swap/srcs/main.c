/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 13:50:54 by seyun             #+#    #+#             */
/*   Updated: 2021/10/14 23:41:29 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	only_3(t_dlst **stack)
{
	if (check_ascend(*stack, 3))
		return ;
	if (((*stack)->num) == ft_min(*stack))
	{
		ft_ra(stack);
		ft_sa(*stack);
		ft_rra(stack);
	}
	else if ((*stack)->num == ft_max(*stack))
	{
		ft_ra(stack);
		if ((*stack)->next->num == ft_min(*stack))
			ft_sa(*stack);
	}
	else
	{
		if ((*stack)->next->num == ft_min(*stack))
			ft_sa(*stack);
		else
			ft_rra(stack);
	}
}

int main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	int i;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	while (*(++argv) != 0)
		init_stack(&stack_a, creat_node(ft_atoi(*argv)));
	if ((argc - 1) == 3)
		only_3(&stack_a);
	for(i=0; i<3; i++)
	{
		printf("%d ", stack_a->num);
		stack_a = stack_a->next;
	}
	return (0);
}
