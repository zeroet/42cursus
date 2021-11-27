/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:25:57 by seyun             #+#    #+#             */
/*   Updated: 2021/11/28 00:09:38 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(t_input *info)
{
	char	**res;
	char	*tmp;
	int		i;

	i = 0;
	res = NULL;
	while (info->envp[i])
	{
		if (!(ft_memcmp(info->envp[i], "PATH=", 4)))
		{	
			tmp = info->envp[i];
			res = ft_split(tmp + 5, ':');
			return (res);
		}
		i++;
	}
	return (NULL);
}

char	*make_cmd(t_input *info, int index)
{
	char	**envp;
	int		i;
	char	*res;
	char	*cmd;

	i = 0;
	envp = get_path(info);
	cmd = ft_strjoin("/", info->argv[index]);
	while (envp[i])
	{
		res = ft_strjoin(envp[i], cmd);
		if (-1 != access(res, X_OK))
		{
			free(envp);
			free(cmd);
			printf("%s ---- ok \n ", res);
			return (res);
		}
		printf("%s ---- not ok\n", res);
		free(res);
		i++;
	}
	free(cmd);
	free(envp);
	return (NULL);
}

t_input	*init_info(int argc, char **argv, char **envp)
{
	t_input	*info;

	info = (t_input *)malloc(sizeof(t_input));
	if (!info)
		return (NULL);
	info->argc = argc;
	info->argv = argv;
	info->envp = envp;
	return (info);
}

int	main(int argc, char **argv, char **envp)
{
	t_input	*info;

	if (argc != 5)
		exit(1);
	info = init_info(argc, argv, envp);
	pipex(info);
	free(info);
	return (0);
}
