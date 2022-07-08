/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:19:39 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 22:19:39 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_cmd_error(char *path, int file_flag)
{
	if (ft_strchr(path, '/') != 0 || file_flag)
	{
		if (my_access(path, F_OK) != 0)
		{
			ft_putstr_fd("minishell: ", 2);
			perror(path);
			return (127);
		}
		if (my_access(path, X_OK) != 0)
		{
			ft_putstr_fd("minishell: ", 2);
			perror(path);
			return (126);
		}
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": command not found\n", 2);
		return (127);
	}
	return (0);
}
