/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envp_by_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:02:34 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:02:34 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*set_envp_by_name(char ***env, char *name, char *new_val)
{
	int		i;
	int		j;
	char	*tmp_str;

	i = 0;
	while ((*env)[i] != NULL)
	{
		j = 0;
		while ((*env)[i][j] && name[j] && (*env)[i][j] != '='
			   && (*env)[i][j] == name[j])
			j++;
		if (((*env)[i][j] == '=' || (*env)[i][j] == '\0') && name[j] == '\0')
		{
			tmp_str = new_env_line(name, new_val);
			if (!tmp_str)
				return (NULL);
			free((*env)[i]);
			(*env)[i] = tmp_str;
			return (name);
		}
		i++;
	}
	if (!add_new_env_to_end(env, name, new_val))
		return (NULL);
	return (name);
}
