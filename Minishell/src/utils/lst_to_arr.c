/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:05:27 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:05:27 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*lst_to_arr(t_list	*lst, size_t element_size, int direction)
{
	int		lst_size;
	void	**arr;
	int		i;
	int		delta;

	lst_size = ft_lstsize(lst);
	arr = (void **)malloc(element_size * (lst_size + 1));
	if (direction)
	{
		i = 0;
		delta = 1;
	}
	else
	{
		i = lst_size - 1;
		delta = -1;
	}
	while (lst)
	{
		arr[i] = lst->content;
		i += delta;
		lst = lst->next;
	}
	arr[lst_size] = NULL;
	return (arr);
}
