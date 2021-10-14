/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:03:14 by seyun             #+#    #+#             */
/*   Updated: 2021/10/14 22:07:05 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_min(t_dlst *lst)
{
	int min;

	min = lst->num;
	if (min > lst->next->num)
		min = lst->next->num;
	if (min > lst->next->next->num)
		min = lst->next->next->num;
	return (min);
}

int		ft_max(t_dlst *lst)
{
	int max;

	max = lst->num;
	if (max < lst->next->num)
		max = lst->next->num;
	if (max < lst->next->next->num)
		max = lst->next->next->num;
	return (max);
}
