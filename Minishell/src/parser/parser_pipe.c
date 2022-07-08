/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:00:43 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 22:00:43 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	add_pipe_stdin(int *tmp_pipe, t_cmd *tmp_cmd)
{
	t_redirect	*r;

	if_error((pipe(tmp_pipe) < 0), "pipe", 1);
	r = new_redirect_data(NULL);
	r->this_redirect_fd = tmp_pipe[1];
	r->fd_to_change = 1;
	r->flags = 0;
	r->mode = 0;
	add_redirect_front(tmp_cmd, r);
}

static void	add_pipe_stdout(int *tmp_pipe, t_cmd *tmp_cmd)
{
	t_redirect	*r;

	r = new_redirect_data(NULL);
	r->this_redirect_fd = tmp_pipe[0];
	r->fd_to_change = 0;
	r->flags = 0;
	r->mode = 0;
	add_redirect(tmp_cmd, r);
}

int	parser_pipe(t_parser_data *pdata, t_list **param)
{
	t_list	*tmp_cmd_lst_item;
	int		tmp_pipe[2];
	int		check_res;

	check_res = check_for_data_arg((*param)->next, 1);
	if (check_res != 0)
		return (258);
	pdata->tmp_cmd->argv = lst_to_arr(pdata->lst_cmd, sizeof (char *), 0);
	ft_lstclear(&pdata->lst_cmd, &do_nothing);
	pdata->lst_cmd = NULL;
	add_pipe_stdin(tmp_pipe, pdata->tmp_cmd);
	tmp_cmd_lst_item = ft_lstnew(pdata->tmp_cmd);
	ft_lstadd_front(&pdata->cmds_lst, tmp_cmd_lst_item);
	pdata->tmp_cmd = new_cmd();
	if (!pdata->tmp_cmd)
		return (1);
	add_pipe_stdout(tmp_pipe, pdata->tmp_cmd);
	return (0);
}
