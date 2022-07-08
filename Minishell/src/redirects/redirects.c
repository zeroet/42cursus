/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:12:15 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:29:16 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_redirect	*new_redirect_data(char *path)
{
	t_redirect	*data;

	data = (t_redirect *)malloc(sizeof(t_redirect));
	if_error(data == NULL, "malloc", 1);
	data->path = NULL;
	if (path != NULL)
	{
		data->path = ft_strdup(path);
		if (data->path == NULL)
		{
			free(data);
			if_error(1, "malloc", 1);
		}
	}
	return (data);
}

void	add_redirect(t_cmd *cmd_ptr, t_redirect *data)
{
	t_list		*new_lst;

	new_lst = ft_lstnew(data);
	if (new_lst == NULL)
	{
		free(data->path);
		free(data);
		if_error(1, "malloc", 1);
	}
	ft_lstadd_back(&(cmd_ptr->redirects), new_lst);
}

void	add_redirect_front(t_cmd *cmd_ptr, t_redirect *data)
{
	t_list		*new_lst;

	new_lst = ft_lstnew(data);
	if (new_lst == NULL)
	{
		free(data->path);
		free(data);
		if_error(1, "malloc", 1);
	}
	ft_lstadd_front(&(cmd_ptr->redirects), new_lst);
}

void	close_redirects(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		if (((t_redirect *)lst->content)->this_redirect_fd != -1)
		{
			close(((t_redirect *)lst->content)->this_redirect_fd);
			((t_redirect *)lst->content)->this_redirect_fd = -1;
		}
		lst = lst->next;
	}
}

void	free_redirect_data(void *param)
{
	t_redirect	*r;

	if (!param)
		return ;
	r = (t_redirect *)param;
	if (r->path)
		free(r->path);
	free(r);
}
