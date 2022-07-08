/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler_prompt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:57:45 by flegg             #+#    #+#             */
/*   Updated: 2022/07/07 23:08:28 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler_prompt(int num)
{
	int	i;

	(void)num;
	i = -1;
	g_sh.last_exit_code = 1;
	while (++i < g_sh.cmd_count)
		kill(g_sh.cmd[i]->pid, SIGKILL);
	if (g_sh.heredoc_pid)
	{
		kill(g_sh.heredoc_pid, SIGKILL);
		if ((write(1, "\n", 1)) == -1)
			exit(1);
	}
	rl_on_new_line();
	rl_redisplay();
	if ((write(2, "  \b\b\n", 5)) == -1)
		exit(1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_sh.last_exit_code = 1;
}
