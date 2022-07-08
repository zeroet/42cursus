/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_worker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:15:16 by flegg             #+#    #+#             */
/*   Updated: 2021/09/17 21:44:07 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	null_cmd_fix(void)
{
	if_error(close(0) == -1, "close", 1);
	if_error(close(1) == -1, "close", 1);
	free_all_globals();
	exit(0);
}

static void	builtin_worker_exec(int i, int (*worker)(int, char **))
{
	int	error_code;

	error_code = worker(ptr_arr_len((void **)g_sh.cmd[i]->argv),
			g_sh.cmd[i]->argv);
	if_error(close(0) == -1, "close", 1);
	if_error(close(1) == -1, "close", 1);
	free_all_globals();
	exit(error_code);
}

static void	exec_worker(int i)
{
	char	*tmp;
	int		error_code;

	tmp = get_full_path(g_sh.cmd[i]->argv[0], g_sh.envp);
	error_code = is_cmd_error(tmp, 0);
	if (error_code != 0)
	{
		free(tmp);
		free_all_globals();
		exit(error_code);
	}
	error_code = execve(tmp, g_sh.cmd[i]->argv, g_sh.envp);
	free(tmp);
	if_error(error_code < 0, g_sh.cmd[i]->argv[0], error_code);
	if_error(close(0) == -1, "close", 1);
	if_error(close(1) == -1, "close", 1);
	free_all_globals();
	exit(error_code);
}

void	child_worker(int i)
{
	int	j;
	int	(*worker)(int, char **);

	apply_redirects(i);
	j = -1;
	while (++j < g_sh.cmd_count)
		close_redirects(g_sh.cmd[j]->redirects);
	if (g_sh.cmd[i]->argv[0] == NULL)
		null_cmd_fix();
	worker = get_builtin_worker(g_sh.cmd[i]->argv[0]);
	if (worker != NULL)
		builtin_worker_exec(i, worker);
	exec_worker(i);
}
