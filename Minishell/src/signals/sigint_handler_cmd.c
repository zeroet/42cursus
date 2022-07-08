/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:57:45 by flegg             #+#    #+#             */
/*   Updated: 2022/07/07 23:07:16 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler_cmd(int num)
{
	int	i;

	(void)num;
	if ((write(2, "\n", 1)) == -1)
		exit(1);
	i = -1;
	g_sh.last_exit_code = 130;
	while (++i < g_sh.cmd_count)
		kill(g_sh.cmd[i]->pid, SIGKILL);
}
