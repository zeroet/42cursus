/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 13:50:54 by seyun             #+#    #+#             */
/*   Updated: 2021/12/22 16:21:58 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	only_3(t_dlst **stack)
{
	if (check_ascend(*stack, 3))
		return ;
	if (((*stack)->num) == ft_min(*stack))
	{
		ft_sa(*stack);
		ft_ra(stack);
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

int	main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	int		i;

	i = argc -1;
	stack_a = NULL;
	stack_b = NULL;
	while (*(++argv) != 0)
		init_stack(&stack_a, creat_node(ft_atoi(*argv)));
	if (argc == 1)
		return (0);
	if (argc >= 2)
	{
		if (i == 3)
			only_3(&stack_a);
		if ((check_descend(stack_a, i)))
			descend_to_ascend(&stack_a, &stack_b, i);
		if (i == 5 && !(check_ascend(stack_a, i)))
			sort_5(&stack_a, &stack_b, i);
		if (i > 3 && i != 5 &&!(check_ascend(stack_a, i)))
			a_to_b(&stack_a, &stack_b, i);
	}
	dlst_clear(stack_a);
	system("leaks push_swap");
	return (0);
}
