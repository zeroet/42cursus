/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_from_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:02:06 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:02:06 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	remove_from_env_loop(char ***env, int env_size,
	char *name, char **new_env)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < env_size)
	{
		j = 0;
		while ((*env)[i][j] && name[j] && (*env)[i][j] != '='
			   && (*env)[i][j] == name[j])
			j++;
		if (((*env)[i][j] == '=' || (*env)[i][j] == '\0') && name[j] == '\0')
			free((*env)[i]);
		else
		{
			new_env[k] = (*env)[i];
			k++;
		}
		i++;
	}
	new_env[k] = NULL;
}

char	**remove_from_env(char ***env, char *name)
{
	int		env_size;
	char	**new_env;

	env_size = ptr_arr_len((void **)*env);
	new_env = (char **)malloc((sizeof(char *) * (env_size + 1)));
	if (!new_env)
		return (NULL);
	remove_from_env_loop(env, env_size, name, new_env);
	free(*env);
	*env = new_env;
	return (new_env);
}
