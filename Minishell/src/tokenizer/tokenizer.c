/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:47:26 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:47:26 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	redirect_token_select(char **p, char **t, t_list **lst)
{
	if (my_strncmp(*t, "<<", 2))
	{
		if (add_special(p, t, lst, "<<") != 0)
			return (0);
		(*t)++;
		(*p)++;
	}
	else if (**t == '<')
	{
		if (add_special(p, t, lst, "<") != 0)
			return (0);
	}
	else if (my_strncmp(*t, ">>", 2))
	{
		if (add_special(p, t, lst, ">>") != 0)
			return (0);
		(*t)++;
		(*p)++;
	}
	else if (**t == '>')
	{
		if (add_special(p, t, lst, ">") != 0)
			return (0);
	}
	return (1);
}

static int	redirect_and_pipe_token_select(char **p, char **t, t_list **lst)
{
	if (**t == '|')
	{
		if (add_special(p, t, lst, "|") != 0)
			return (0);
	}
	else
	{
		if (!redirect_token_select(p, t, lst))
			return (0);
	}
	return (1);
}

static int	tokenizer_loop(char **p, char **t, t_list **lst)
{
	int		qflag;
	int		dqflag;

	qflag = 0;
	dqflag = 0;
	while (**t)
	{
		if (**t == '\'' && !dqflag)
			qflag = !qflag;
		else if (**t == '\"' && !qflag)
			dqflag = !dqflag;
		else if (is_space(**t) && !qflag && !dqflag)
		{
			if (add_arg_to_lst(p, t, lst) != 0)
				return (0);
		}
		else if (!qflag && !dqflag)
		{
			if (!redirect_and_pipe_token_select(p, t, lst))
				return (0);
		}
		(*t)++;
	}
	return (1);
}

t_list	*tokenizer(char **s)
{
	char	*p;
	char	*t;
	t_list	*lst;

	if (!s || !(*s))
		return (NULL);
	if (ft_strlen(*s) < 1)
		return (NULL);
	if (dollar_replace(s))
		return (NULL);
	p = *s;
	lst = NULL;
	t = p;
	if (!tokenizer_loop(&p, &t, &lst))
		return (NULL);
	if (t - p > 0)
	{
		if (add_arg_to_lst(&p, &t, &lst) != 0)
			return (NULL);
	}
	return (lst);
}
