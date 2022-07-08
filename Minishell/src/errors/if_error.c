/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:18:01 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 22:18:01 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	if_error(int is_true, const char *perror_str, int ret)
{
	if (is_true)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(perror_str);
		free_all_globals();
		exit(ret);
	}
}
