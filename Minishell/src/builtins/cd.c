/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 23:13:17 by flegg             #+#    #+#             */
/*   Updated: 2021/09/10 23:13:17 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	set_env_to_current_pwd(char ***envp, char *name)
{
	char	*pwd;
	char	*tmp_str;

	pwd = NULL;
	pwd = my_getcwd(pwd);
	if (!pwd)
		return (print_perror(-1, "malloc"));
	tmp_str = set_envp_by_name(envp, name, pwd);
	free(pwd);
	if (!tmp_str)
		return (print_perror(-1, "malloc"));
	return (0);
}

static int	basic_cd_worker(char *path)
{
	if (set_env_to_current_pwd(&g_sh.envp, "OLDPWD"))
		return (-1);
	if (chdir(path) == -1)
		return (ft_error(strerror(errno), 1, "cd", path));
	if (set_env_to_current_pwd(&g_sh.envp, "PWD"))
		return (-1);
	return (0);
}

static int	hyphen_worker(char *path)
{
	path = ft_strdup(path);
	if (!path)
		return (print_perror(-1, "malloc"));
	if (basic_cd_worker(path))
	{
		free(path);
		return (-1);
	}
	free(path);
	ft_putendl_fd(get_envp_by_name(g_sh.envp, "PWD", 3), 1);
	return (0);
}

int	cd(int argc, char **argv)
{
	char	*tmp;

	if (argc == 1)
	{
		tmp = get_envp_by_name(g_sh.envp, "HOME", 4);
		if (!tmp)
			return (ft_error("HOME not set", 1, "cd", NULL));
		return (basic_cd_worker(tmp));
	}
	else
	{
		if (my_strcmp(argv[1], "-"))
		{
			tmp = get_envp_by_name(g_sh.envp, "OLDPWD", 6);
			if (!tmp)
				return (ft_error("OLDPWD not set", 1, "cd", NULL));
			return (hyphen_worker(tmp));
		}
		else
			return (basic_cd_worker(argv[1]));
	}
}
