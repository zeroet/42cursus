/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_special.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:57:45 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 22:57:45 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	add_special(char **p, char **t, t_list **lst, char *special)
{
	if (add_arg_to_lst(p, t, lst) != 0)
		return (-1);
	if (add_to_lst(special, lst) != 0)
		return (-1);
	return (0);
}
