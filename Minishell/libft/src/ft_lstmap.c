/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 23:30:45 by flegg             #+#    #+#             */
/*   Updated: 2020/11/18 19:08:32 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*lstitem;

	if (!lst || !f)
		return ((void *)0);
	newlst = (void *)0;
	while (lst)
	{
		lstitem = ft_lstnew((*f)(lst->content));
		if (!lstitem)
		{
			ft_lstclear(&newlst, del);
			return ((void *)0);
		}
		ft_lstadd_back(&newlst, lstitem);
		lst = lst->next;
	}
	return (newlst);
}
