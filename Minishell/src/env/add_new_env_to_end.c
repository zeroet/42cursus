/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_env_to_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:01:27 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:01:27 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**add_new_env_to_end(char ***env, char *name, char *new_val)
{
	int		env_size;
	char	**new_env;
	char	*tmp_str;
	int		i;

	env_size = ptr_arr_len((void **)*env);
	new_env = (char **)malloc((sizeof(char *) * (env_size + 2)));
	if (!new_env)
		return (NULL);
	i = 0;
	while (i < env_size)
	{
		new_env[i] = (*env)[i];
		i++;
	}
	new_env[i] = NULL;
	new_env[i + 1] = NULL;
	tmp_str = new_env_line(name, new_val);
	if (!tmp_str)
		return (NULL);
	new_env[i] = tmp_str;
	free(*env);
	*env = new_env;
	return (new_env);
}
