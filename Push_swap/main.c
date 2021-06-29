/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 13:50:54 by seyun             #+#    #+#             */
/*   Updated: 2021/06/29 22:45:39 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	init_stack(t_list **list, t_list *node)
{
	if (!lst || !node)
		return ;
	if (!lst)
		*lst = node;
	else
	{
		(*lst)->prev->next = node;
		

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	while (*(++argv))
		init_stack(&stack_a, create_node(ft_atoi(*argv)));
