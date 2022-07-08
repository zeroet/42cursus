/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_wait.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:12:58 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:12:58 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	close_and_wait(pid_t pid)
{
	int		tmp_exit_code;
	int		j;
	pid_t	pid2;
	int		exit_code;

	j = -1;
	while (++j < g_sh.cmd_count)
		close_redirects(g_sh.cmd[j]->redirects);
	exit_code = 0;
	pid2 = wait(&tmp_exit_code);
	while (pid2 >= 0)
	{
		if (pid2 == pid)
			exit_code = tmp_exit_code;
		pid2 = wait(&tmp_exit_code);
	}
	exit_code = exit_code >> 8;
	g_sh.last_exit_code = exit_code;
	return (exit_code);
}
