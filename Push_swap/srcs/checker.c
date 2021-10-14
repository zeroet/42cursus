/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:50 by seyun             #+#    #+#             */
/*   Updated: 2021/10/14 22:00:27 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_ascend(t_dlst *lst, int len)
{
	while (len--)
	{
		if (lst->num > lst->next->num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int		check_descend(t_dlst *lst, int len)
{
	while (len--)
	{
		if (lst->num < lst->next->num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	check_duplicates(t_dlst *lst)
{
	t_dlst *new;

	new = lst->prev;
	while (lst != new)
	{
		if (new->num == lst->num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

