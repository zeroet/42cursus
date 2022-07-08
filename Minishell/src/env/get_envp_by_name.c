/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_by_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:00:04 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:00:04 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_envp_by_name(char **env, char *name, int name_len)
{
	int	i;
	int	j;

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] && name[j] && j < name_len
			   && env[i][j] != '=' && env[i][j] == name[j])
			j++;
		if (env[i][j] == '=' && (name[j] == '\0' || j == name_len))
			return (env[i] + j + 1);
		i++;
	}
	return (NULL);
}
