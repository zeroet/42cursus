/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_shlvl_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:45:01 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 22:45:01 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	update_shlvl_env(void)
{
	int		lvl;
	char	*shlvl;
	char	*res;

	shlvl = get_envp_by_name(g_sh.envp, "SHLVL", 5);
	if (!shlvl)
	{
		if (!set_envp_by_name(&g_sh.envp, "SHLVL", "1"))
			return (-1);
		return (0);
	}
	lvl = ft_atoi(shlvl);
	if (lvl < 0)
	{
		if (!set_envp_by_name(&g_sh.envp, "SHLVL", "0"))
			return (-1);
		return (0);
	}
	lvl++;
	shlvl = ft_itoa(lvl);
	res = set_envp_by_name(&g_sh.envp, "SHLVL", shlvl);
	free(shlvl);
	if (!res)
		return (-1);
	return (0);
}
