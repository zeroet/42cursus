/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:43:42 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:43:42 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	add_to_lst(char *new_str, t_list **lst)
{
	char	*tmp;
	t_list	*lst_item;

	tmp = ft_strdup(new_str);
	if (!tmp)
		return (-1);
	lst_item = ft_lstnew(tmp);
	if (!lst_item)
	{
		free(tmp);
		return (-1);
	}
	ft_lstadd_front(lst, lst_item);
	return (0);
}
