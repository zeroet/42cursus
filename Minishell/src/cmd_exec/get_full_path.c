/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:16:57 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:16:57 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*test_path(char *path, char **split_path)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = -1;
	while (split_path[++i])
	{
		tmp = ft_strjoin(split_path[i], "/");
		if (!tmp)
			return (NULL);
		tmp2 = ft_strjoin(tmp, path);
		free(tmp);
		if (!tmp2)
			return (NULL);
		if (my_access(tmp2, X_OK) == 0)
			return (tmp2);
		free(tmp2);
	}
	return (ft_strdup(path));
}

char	*get_full_path(char *path, char **envp)
{
	char	*path_env;
	char	**split_path;
	char	*tmp;

	if (ft_strchr(path, '/') != 0)
		return (ft_strdup(path));
	path_env = get_envp_by_name(envp, "PATH", 4);
	if (path_env == NULL)
		return (ft_strdup(path));
	split_path = ft_split(path_env, ':');
	if (!split_path)
		return (NULL);
	tmp = test_path(path, split_path);
	char_array_free(split_path);
	return (tmp);
}
