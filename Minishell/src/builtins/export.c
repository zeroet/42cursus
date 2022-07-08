/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: along <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:45:06 by along             #+#    #+#             */
/*   Updated: 2022/07/07 23:05:39 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**sort(char	**env)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	i = 0;
	size = ptr_arr_len((void **) env);
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (ft_strcmp(env[j - 1], env[j]) > 0)
			{
				tmp = env[j - 1];
				env[j - 1] = env[j];
				env[j] = tmp;
			}
			j--;
		}
		i++;
	}
	return (env);
}

static void	print_env_elem(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if ((write(1, str, i)) == -1)
		exit(1);
	if (str[i++] == '=')
	{
		if ((write(1, "=\"", 2)) == -1)
			exit(1);
		ft_putstr_fd(str + i, 1);
		if ((write(1, "\"", 1)) == -1)
			exit(1);
	}
	if ((write(1, "\n", 1)) == -1)
		exit(1);
}

static int	add_env_worker(char *str)
{
	int		i;

	i = dollar_name_len(str);
	if (i < 1 || (str[i] != '\0' && str[i] != '=' && str[i] != '+')
		|| (str[i] == '+' && str[i + 1] != '='))
	{
		ft_error("not a valid identifier", 1, "export", str);
		return (1);
	}
	if (str[i] == '\0')
		return (export_endl_worker(str, i));
	if (str[i] == '=')
		return (export_equal_worker(str, i));
	if (str[i++] == '+')
		return (export_plus_worker(str, i));
	return (0);
}

static void	export_print_all(void)
{
	char	**tmp_env;
	int		i;

	tmp_env = make_env(g_sh.envp);
	sort(tmp_env);
	i = -1;
	while (tmp_env[++i])
	{
		ft_putstr_fd("declare -x ", 1);
		print_env_elem(tmp_env[i]);
	}
	char_array_free(tmp_env);
}

int	export(int argc, char **argv)
{
	int		i;
	int		exit_code;
	int		tmp_exit_code;

	exit_code = 0;
	if (argc == 1)
		export_print_all();
	else
	{
		i = 0;
		while (argv[++i])
		{
			tmp_exit_code = add_env_worker(argv[i]);
			if (tmp_exit_code == -1)
				return (-1);
			else if (tmp_exit_code != 0)
				exit_code = tmp_exit_code;
		}
	}
	return (exit_code);
}
