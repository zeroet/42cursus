/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:33:13 by seyun             #+#    #+#             */
/*   Updated: 2021/10/16 21:29:01 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int *set_table(t_dlst *stack, int len)
{
	int *table;
	int i;

	i = 0;
	if (!stack)
		return ;
	table = (int *)malloc(sizeof(int) *len);
	if (!table)
		return ;
	while (i < len)
	{
		table[i] = stack->num;
		stack = stack->next;
		i++;
	}
	return (table);
}

int		set_pivot(t_dlst *stack, int len)
{
	int *table;
	int pivot;
	int i;
	int j;
	int count;

	pviot = 0;
	table = set_number(stack, len);
	i = -1;
	while (++i < len)
	{
		j = 0;
		count = 0;
		while (j < len)
			if (table[i] > table[j++])
				count++;
		if (count == (len / 2))
		{
			pivot = table[i];
			free(table);
			return (pivot);
		}
	}
	pivot = table[0];
	free(table);
	return (pivot);
}
