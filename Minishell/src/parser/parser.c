/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:05:51 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 22:05:51 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	*get_parser_worker(char *str)
{
	int	i;

	i = 1;
	while (i < OPERATOR_COUNT)
	{
		if (my_strcmp(g_sh.parser_operators[i].str, str))
			return (g_sh.parser_operators[i].worker);
		i++;
	}
	return (g_sh.parser_operators[0].worker);
}

static	int	add_ending_cmd(t_parser_data *pdata)
{
	t_list	*tmp_cmd_lst_item;

	pdata->tmp_cmd->argv = lst_to_arr(pdata->lst_cmd, sizeof (char *), 0);
	ft_lstclear(&pdata->lst_cmd, &do_nothing);
	pdata->lst_cmd = NULL;
	tmp_cmd_lst_item = ft_lstnew(pdata->tmp_cmd);
	ft_lstadd_front(&pdata->cmds_lst, tmp_cmd_lst_item);
	return (0);
}

static int	pdata_init(t_parser_data *pdata)
{
	pdata->lst_cmd = NULL;
	pdata->tmp_cmd = new_cmd();
	if (!pdata->tmp_cmd)
		return (-1);
	pdata->cmds_lst = NULL;
	return (0);
}

static int	parser_loop(t_list *current, t_parser_data *pdata, int *ret_flag)
{
	int	(*worker)(t_parser_data *, t_list **);
	int	worker_res;

	*ret_flag = 0;
	while (current)
	{
		if (((char *)(current->content))[0] == '\0')
		{
			current = current->next;
			continue ;
		}
		g_sh.heredoc_exit_status = 0;
		worker = get_parser_worker(current->content);
		worker_res = worker(pdata, &current);
		signal(SIGINT, sigint_handler_prompt);
		signal(SIGQUIT, sigquit_handler_prompt);
		if (worker_res != 0)
			return (worker_res);
		if (g_sh.heredoc_exit_status)
			return (g_sh.last_exit_code);
		if (current)
			current = current->next;
	}
	*ret_flag = 1;
	return (0);
}

int	parser(t_list **lst)
{
	t_list			*current;
	t_parser_data	pdata;
	int				ret_flag;
	int				exit_code;

	*lst = ft_lstreverse(*lst);
	current = *lst;
	if (pdata_init(&pdata) == -1)
		return (-1);
	if (my_strcmp(current->content, "|"))
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (258);
	}
	exit_code = parser_loop(current, &pdata, &ret_flag);
	if (!ret_flag)
		return (exit_code);
	if (add_ending_cmd(&pdata))
		return (-1);
	g_sh.cmd = NULL;
	g_sh.cmd = lst_to_arr(pdata.cmds_lst, sizeof (t_cmd *), 0);
	ft_lstclear(&pdata.cmds_lst, &do_nothing);
	return (0);
}
