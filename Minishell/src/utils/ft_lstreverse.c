/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:01:53 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 22:01:53 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	*ft_lstreverse(t_list *old)
{
	t_list	*new_head;
	t_list	*tmp;

	new_head = old;
	old = old->next;
	new_head->next = NULL;
	while (old)
	{
		tmp = old;
		old = old->next;
		tmp->next = new_head;
		new_head = tmp;
	}
	return (new_head);
}
