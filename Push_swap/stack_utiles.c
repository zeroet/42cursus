/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:55:30 by seyun             #+#    #+#             */
/*   Updated: 2021/10/14 13:58:50 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	dlst_clear(t_dlst *lst)
{
	t_dlst *tmp;

	lst->prev->next = NULL;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
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

t_dlst *creat_node(int num)
{
	t_dlst *new_node;

	new_node = (t_dlst *)malloc(sizeof(t_dlst));
	if (new_node == NULL)
		return (0);
	new_node->num = num;
	new_node->prev = new_node;
	new_node->next = new_node;
	return (new_node);
}

