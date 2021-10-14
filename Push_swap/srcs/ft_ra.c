/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:30:22 by seyun             #+#    #+#             */
/*   Updated: 2021/10/14 22:50:10 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_dlst **lst)
{
	if (!*lst)
		return ;
	*lst = (*lst)->next;
	write(1, "ra\n", 3);
}

void	ft_rb(t_dlst **lst)
{
	if (!*lst)
		return ;
	*lst = (*lst)->next;
	write(1, "rb\n", 3);
}

void	ft_rr(t_dlst **stack_a, t_dlst **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}
