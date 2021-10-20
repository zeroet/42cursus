/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:50 by seyun             #+#    #+#             */
/*   Updated: 2021/10/20 22:08:13 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_ascend(t_dlst *lst, int len)
{
	if (!len || !lst)
		return (0);
	while (--len)
	{
		if (lst->num > lst->next->num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	check_descend(t_dlst *lst, int len)
{
	if (!len || !lst)
		return (0);
	while (--len)
	{
		if (lst->num < lst->next->num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	check_duplicates(t_dlst *lst)
{
	t_dlst	*new;

	new = lst->prev;
	while (lst != new)
	{
		if (new->num == lst->num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	stack_size(t_dlst *lst)
{
	int	last;
	int	cnt;

	if (!lst)
		return (0);
	cnt = 0;
	last = lst->prev->num;
	while (lst->num != last)
	{
		cnt++;
		lst = lst->next;
	}
	return (++cnt);
}
