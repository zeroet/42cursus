/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: along <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:45:06 by along             #+#    #+#             */
/*   Updated: 2021/09/10 22:45:06 by along            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	del_env_worker(char *str)
{
	int	i;

	i = dollar_name_len(str);
	if (i < 1 || str[i] != '\0')
	{
		ft_error("not a valid identifier", 1, "unset", str);
		return (1);
	}
	if (!remove_from_env(&g_sh.envp, str))
		return (-1);
	return (0);
}

int	unset(int argc, char **argv)
{
	int	i;
	int	exit_code;
	int	tmp_exit_code;

	exit_code = 0;
	if (argc > 1)
	{
		i = 0;
		while (argv[++i])
		{
			tmp_exit_code = del_env_worker(argv[i]);
			if (tmp_exit_code == -1)
				return (-1);
			else if (tmp_exit_code != 0)
				exit_code = tmp_exit_code;
		}
	}
	return (exit_code);
}
