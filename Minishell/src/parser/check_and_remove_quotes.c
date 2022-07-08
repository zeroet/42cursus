/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_remove_quotes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:48:53 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:48:53 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_errors(int qflag, int dqflag)
{
	if (qflag)
	{
		ft_putstr_fd(
			"minishell: unexpected EOF while looking for matching `\'\'\n", 2);
		ft_putstr_fd(
			"minishell: syntax error: unexpected end of file\n", 2);
		return (258);
	}
	if (dqflag)
	{
		ft_putstr_fd(
			"minishell: unexpected EOF while looking for matching `\"\'\n", 2);
		ft_putstr_fd(
			"minishell: syntax error: unexpected end of file\n", 2);
		return (258);
	}
	return (0);
}

int	check_and_remove_quotes(char *str)
{
	int		qflag;
	int		dqflag;
	int		i;
	int		new;

	qflag = 0;
	dqflag = 0;
	i = 0;
	new = i;
	while (str[i])
	{
		if (str[i] == '\'' && !dqflag)
			qflag = !qflag;
		else if (str[i] == '\"' && !qflag)
			dqflag = !dqflag;
		else
		{
			str[new] = str[i];
			new++;
		}
		i++;
	}
	str[new] = '\0';
	return (check_errors(qflag, dqflag));
}
