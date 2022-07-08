/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:02:44 by flegg             #+#    #+#             */
/*   Updated: 2021/09/10 16:02:44 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env(int argc, char **argv)
{
	int		i;

	(void)argc;
	(void)argv;
	i = 0;
	while (g_sh.envp[i])
	{
		if (ft_strchr(g_sh.envp[i], '='))
			ft_putendl_fd(g_sh.envp[i], 1);
		i++;
	}
	return (0);
}
