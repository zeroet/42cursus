/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_worker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:12:15 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 22:58:26 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	dollar_name_len(char *i)
{
	char	*start_pos;

	start_pos = i;
	if ((*i >= 'A' && *i <= 'Z') || (*i >= 'a' && *i <= 'z') || *i == '_')
		i++;
	else
	{
		i--;
		return (0);
	}
	while ((*i >= 'A' && *i <= 'Z') || (*i >= 'a' && *i <= 'z')
		|| *i == '_' || (*i >= '0' && *i <= '9'))
		i++;
	return ((int)(i - start_pos));
}

static int	replace_question_sign(char **new_s, char **str, int *i)
{
	char	*tmp_str_num;

	tmp_str_num = ft_itoa(g_sh.last_exit_code);
	if (!tmp_str_num)
		return (1);
	*new_s = strdup_insert(*str, tmp_str_num,
			*i, *i + 2);
	free(tmp_str_num);
	(*i)++;
	return (0);
}

static int	replace_dollar_general(char **new_s, char **str, int *i)
{
	int		name_len;
	char	*env_val;

	env_val = NULL;
	name_len = dollar_name_len(*str + *i + 1);
	if (name_len == 0)
		return (0);
	env_val = get_envp_by_name(g_sh.envp, *str + *i + 1, name_len);
	if (env_val == NULL)
		*new_s = strdup_insert(*str, "", *i, *i + name_len + 1);
	else
		*new_s = strdup_insert(*str, env_val, *i, *i + name_len + 1);
	if (env_val != NULL)
		*i += ft_strlen(env_val);
	return (1);
}

int	dollar_worker(char **str, int *i)
{
	char	*new_s;

	if ((*str)[*i + 1] == '?')
	{
		if (replace_question_sign(&new_s, str, i) != 0)
			return (1);
	}
	else
	{
		if (replace_dollar_general(&new_s, str, i) != 1)
			return (0);
	}
	if (!new_s)
		return (1);
	free(*str);
	*str = new_s;
	(*i)--;
	return (0);
}
