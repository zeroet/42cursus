/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:28:49 by flegg             #+#    #+#             */
/*   Updated: 2022/07/07 23:05:58 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pwd(int argc, char **argv)
{
	char	*dir;

	(void)argc;
	(void)argv;
	dir = NULL;
	dir = my_getcwd(dir);
	if (!dir)
		return (print_perror(errno, "getcwd"));
	ft_putstr_fd(dir, 1);
	free(dir);
	if ((write(1, "\n", 1)) == -1)
		exit(1);
	return (0);
}
