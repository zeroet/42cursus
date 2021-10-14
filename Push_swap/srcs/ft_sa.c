/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:15:44 by seyun             #+#    #+#             */
/*   Updated: 2021/10/14 23:06:27 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_dlst *lst)
{
	int tmp;

	if (!lst)
		return ;
	tmp = lst->num;
	lst->num = lst->next->num;
	lst->next->num = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_dlst *lst)
{
	int tmp;

	if (!lst)
		return ;
	tmp = lst->num;
	lst->num = lst->next->num;
	lst->next->num = tmp;
	write(1, "sb\n", 3);
}

void	ft_ss(t_dlst *stack_a, t_dlst *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}
