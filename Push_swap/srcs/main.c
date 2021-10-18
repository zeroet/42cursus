/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 13:50:54 by seyun             #+#    #+#             */
/*   Updated: 2021/10/18 17:16:43 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define Input (argc - 1)

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

	if (argc <= 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	while (*(++argv) != 0)
		init_stack(&stack_a, creat_node(ft_atoi(*argv)));
	if (Input == 3)
		only_3(&stack_a);
	if ((check_descend(stack_a, Input)))
		descend_to_ascend(&stack_a, &stack_b, Input);
	if (Input > 3 && !(check_ascend(stack_a, Input)))
		A_to_B(&stack_a, &stack_b, Input);
	return (0);
}
