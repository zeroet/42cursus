/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_default.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:49:46 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:49:46 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parser_default(t_parser_data *pdata, t_list **param)
{
	if (check_and_remove_quotes((*param)->content))
		return (2);
	if (add_to_lst((*param)->content, &pdata->lst_cmd))
		return (1);
	return (0);
}
