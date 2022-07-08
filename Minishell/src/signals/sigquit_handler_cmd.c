/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigquit_handler_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:57:45 by flegg             #+#    #+#             */
/*   Updated: 2022/07/07 23:09:14 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigquit_handler_cmd(int num)
{
	int	i;

	(void)num;
	i = -1;
	while (++i < g_sh.cmd_count)
		kill(g_sh.cmd[i]->pid, SIGKILL);
	g_sh.last_exit_code = 131;
	if ((write(2, "Quit: 3\n", 8)) == -1)
		exit(1);
}
