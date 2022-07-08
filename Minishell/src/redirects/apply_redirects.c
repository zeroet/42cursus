/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:12:15 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:29:16 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	pipe_worker(t_redirect *r)
{
	if_error(dup2(r->this_redirect_fd,
			r->fd_to_change) == -1, "dup2", 1);
	if_error(close(r->this_redirect_fd)
		== -1, "close", 1);
	r->this_redirect_fd = -1;
}

static void	redirect_worker(t_redirect *r)
{
	r->this_redirect_fd = open(r->path, r->flags, r->mode);
	if_error(r->this_redirect_fd < 0, r->path, 1);
	if_error(dup2(r->this_redirect_fd,
			r->fd_to_change) == -1, "dup2", 1);
	if_error(close(r->this_redirect_fd)
		== -1, "close", 1);
	r->this_redirect_fd = -1;
}

void	apply_redirects(int i)
{
	t_list	*p;

	p = g_sh.cmd[i]->redirects;
	while (p)
	{
		if (((t_redirect *)(p->content))->path == NULL)
			pipe_worker((t_redirect *)(p->content));
		else
			redirect_worker((t_redirect *)(p->content));
		p = p->next;
	}
}
