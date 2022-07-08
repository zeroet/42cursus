/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:06:31 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:06:31 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_access(char *path, int flag)
{
	struct stat	buf;

	if (stat(path, &buf) != 0)
		return (-1);
	if (flag == X_OK)
	{
		if (buf.st_mode & S_IXUSR)
			return (0);
		else
		{
			errno = EACCES;
			return (-1);
		}
	}
	return (0);
}
