/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:14:59 by flegg             #+#    #+#             */
/*   Updated: 2022/07/07 23:04:13 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\f' || c == '\r' || c == '\v')
		return (1);
	return (0);
}

static void	get_exit_code_extraction(char **str, int *minus_flag)
{
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-')
	{
		*minus_flag = 1;
		(*str)++;
	}
}

static	int	get_exit_code(char *str)
{
	unsigned long long	res;
	int					int_res;
	int					minus_flag;

	minus_flag = 0;
	res = 0;
	get_exit_code_extraction(&str, &minus_flag);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
		if (res > 9223372036854775807)
			return (-1);
	}
	while (ft_isspace(*str))
		str++;
	if (*str != '\0')
		return (-1);
	int_res = (int)(res % 256);
	if (minus_flag && int_res != 0)
		int_res = 256 - int_res;
	return (int_res);
}

static	void	free_all_and_exit(int exit_val, int use_global_exitcode)
{
	free_all_globals();
	if (use_global_exitcode)
		exit_val = g_sh.last_exit_code;
	exit(exit_val);
}

int	exit_builtin(int argc, char **argv)
{
	int	res;

	if ((write(2, "exit\n", 5)) == -1)
		exit(1);
	if (argc == 1)
		free_all_and_exit(0, 1);
	else if (argc == 2)
	{
		res = get_exit_code(argv[1]);
		if (res < 0)
			free_all_and_exit(
				ft_error("numeric argument required", 255,
					"exit", argv[1]), 0);
		free_all_and_exit(res, 0);
	}
	else if (argc > 2)
		return (ft_error("too many arguments", 1, "exit", NULL));
	return (1);
}
