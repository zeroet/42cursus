/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg_to_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:41:06 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:41:06 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	add_arg_to_lst(char **p, char **t, t_list **lst)
{
	char	*tmp;
	t_list	*lst_item;

	if (*t - *p > 0)
	{
		tmp = ft_strdupn(*p, *t - *p);
		if (!tmp)
			return (-1);
		lst_item = ft_lstnew(tmp);
		if (!lst_item)
		{
			free(tmp);
			return (-1);
		}
		ft_lstadd_front(lst, lst_item);
	}
	*p = *t + 1;
	return (0);
}
