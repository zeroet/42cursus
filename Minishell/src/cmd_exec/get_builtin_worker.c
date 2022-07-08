/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin_worker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:13:27 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:13:27 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*get_builtin_worker(char *cmd_name)
{
	static char	*builtin_names[8] = {"echo", "cd",
		"pwd", "export", "unset", "env", "exit", NULL};
	static	int	(*builtins[8])(int, char **) = {echo, cd,
		pwd, export, unset, env, exit_builtin, NULL};
	int			k;

	if (!cmd_name)
		return (NULL);
	k = 0;
	while (builtin_names[k] != NULL && !my_strcmp(cmd_name, builtin_names[k]))
		k++;
	return (builtins[k]);
}
