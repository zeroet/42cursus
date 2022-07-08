/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:57:45 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 22:57:45 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	dollar_replace(char **str)
{
	int		qflag;
	int		dqflag;
	int		i;

	qflag = 0;
	dqflag = 0;
	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\'' && !dqflag)
			qflag = !qflag;
		else if ((*str)[i] == '\"' && !qflag)
			dqflag = !dqflag;
		else if ((*str)[i] == '$' && !qflag)
		{
			if (dollar_worker(str, &i))
				return (1);
		}
		i++;
	}
	return (0);
}
