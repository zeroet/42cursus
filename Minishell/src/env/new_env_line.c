/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:00:51 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:00:51 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*new_env_line(char *name, char *val)
{
	char	*tmp_str;
	char	*tmp_str2;

	if (val)
	{
		tmp_str = ft_strjoin(name, "=");
		if (!tmp_str)
			return (NULL);
		tmp_str2 = ft_strjoin(tmp_str, val);
		free(tmp_str);
		if (!tmp_str2)
			return (NULL);
		return (tmp_str2);
	}
	else
	{
		tmp_str = ft_strdup(name);
		return (tmp_str);
	}
}
