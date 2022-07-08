/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_data_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:32:08 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:32:08 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_for_data_arg(t_list *lst_item, int pipe_flag)
{
	int	i;
	int	operators_count_to_check;

	if (lst_item == NULL)
	{
		ft_putstr_fd(
			"minishell: syntax error near unexpected token `newline'\n", 2);
		return (2);
	}
	i = 1;
	operators_count_to_check = OPERATOR_COUNT;
	if (pipe_flag)
		operators_count_to_check = 2;
	while (i < operators_count_to_check)
	{
		if (my_strcmp(g_sh.parser_operators[i].str, lst_item->content))
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			ft_putstr_fd(g_sh.parser_operators[i].str, 2);
			ft_putstr_fd("'\n", 2);
			return (i);
		}
		i++;
	}
	return (0);
}
