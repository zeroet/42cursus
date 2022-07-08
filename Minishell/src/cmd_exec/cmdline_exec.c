/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:50:53 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:50:53 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	builtin_only_worker(int *exit_code)
{
	int		(*worker)(int, char **);
	int		old_stdin;
	int		old_stdout;

	worker = get_builtin_worker(g_sh.cmd[0]->argv[0]);
	if (worker)
	{
		old_stdin = dup(STDIN_FILENO);
		old_stdout = dup(STDOUT_FILENO);
		apply_redirects(0);
		close_redirects(g_sh.cmd[0]->redirects);
		*exit_code = worker(ptr_arr_len((void **)g_sh.cmd[0]->argv),
				g_sh.cmd[0]->argv);
		if_error(close(0) == -1, "close", 1);
		if_error(close(1) == -1, "close", 1);
		dup2(old_stdin, STDIN_FILENO);
		close(old_stdin);
		dup2(old_stdout, STDOUT_FILENO);
		close(old_stdout);
		g_sh.last_exit_code = *exit_code;
		return (1);
	}
	return (0);
}

int	cmdline_exec(void)
{
	int		i;
	int		exit_code;

	signal(SIGINT, sigint_handler_cmd);
	signal(SIGQUIT, sigquit_handler_cmd);
	if (g_sh.cmd_count == 1 && builtin_only_worker(&exit_code))
		return (exit_code);
	i = 0;
	while (i < g_sh.cmd_count)
	{
		g_sh.cmd[i]->pid = fork();
		if (g_sh.cmd[i]->pid == 0)
			child_worker(i);
		else if (g_sh.cmd[i]->pid < 0)
			if_error(1, "fork", 128);
		i++;
	}
	if (g_sh.cmd_count > 0)
		exit_code = close_and_wait(g_sh.cmd[--i]->pid);
	else
		exit_code = 0;
	return (exit_code);
}
