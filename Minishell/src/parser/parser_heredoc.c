/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:00:43 by flegg             #+#    #+#             */
/*   Updated: 2022/07/07 23:06:47 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static	int	replace_only_dollar(char **str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '$')
		{
			if (dollar_worker(str, &i))
				return (1);
		}
		i++;
	}
	return (0);
}

static void	gnl_worker(char **line, int *tmp_pipe, t_list **param)
{
	int		res;

	res = get_next_line(0, line);
	if (res < 0)
	{
		get_next_line(-42, NULL);
		free_all_globals();
		exit(1);
	}
	if (replace_only_dollar(line))
	{
		free(*line);
		get_next_line(-42, NULL);
		free_all_globals();
		exit(1);
	}
	if (res == 0 || my_strcmp(*line, (*param)->next->content))
	{
		free(*line);
		close(tmp_pipe[1]);
		get_next_line(-42, NULL);
		free_all_globals();
		exit(0);
	}
}

static void	heredoc_parent_worker(int *tmp_pipe, t_parser_data *pdata)
{
	int			res;
	t_redirect	*r;

	wait(&res);
	close(tmp_pipe[1]);
	r = new_redirect_data(NULL);
	r->this_redirect_fd = tmp_pipe[0];
	r->fd_to_change = 0;
	r->flags = 0;
	r->mode = 0;
	add_redirect(pdata->tmp_cmd, r);
}

static void	heredoc_child_worker(int *tmp_pipe, t_list **param)
{
	char	*line;

	close(tmp_pipe[0]);
	while (1)
	{
		if ((write(2, "> ", 2)) == -1)
			exit(1);
		gnl_worker(&line, tmp_pipe, param);
		if ((write(tmp_pipe[1], line, ft_strlen(line))) == -1)
			exit(1);
		if ((write(tmp_pipe[1], "\n", 1)) == -1)
			exit(1);
		free(line);
	}
}

int	parser_heredoc(t_parser_data *pdata, t_list **param)
{
	int		tmp_pipe[2];

	if (check_for_data_arg((*param)->next, 0))
		return (258);
	if (check_and_remove_quotes((*param)->next->content))
		return (258);
	if_error((pipe(tmp_pipe) < 0), "pipe", 1);
	signal(SIGINT, sigint_handler_heredoc);
	signal(SIGQUIT, sigquit_handler_heredoc);
	g_sh.heredoc_pid = fork();
	if_error((g_sh.heredoc_pid < 0), "fork", 1);
	if (g_sh.heredoc_pid == 0)
		heredoc_child_worker(tmp_pipe, param);
	else if (g_sh.heredoc_pid > 0)
		heredoc_parent_worker(tmp_pipe, pdata);
	g_sh.heredoc_pid = 0;
	*param = (*param)->next;
	return (0);
}
