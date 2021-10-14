/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 13:50:54 by seyun             #+#    #+#             */
/*   Updated: 2021/10/14 14:22:40 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	only_3(t_dlst *stack)
{
	if (check_aescend(stack, 3))
		return ;
	if ((*stack->num) == ft_min(stack))
	{
		ft_ra(stack);
		if (!((*stack->num) == ft_max(stack)))
			ft_sa(stack);
	}
	else if ((*stack->num) == ft_max(stack))
	{
		if ((*stack->next->num) < (*stack->next->next-num))
			ft_sa(stack);
	}
	else
	{
		ft_ra(stack);
		only_3(stack);
	}
}

int main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	while (*(++argv) != 0)
		init_stack(&stack_a, creat_node(ft_atoi(*argv)));
	if ((argc - 1) == 3)
		only_3(stack_a);
	return (0);
}

