/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:04:49 by flegg             #+#    #+#             */
/*   Updated: 2021/09/15 21:04:49 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*strdup_insert(char *str, char *new, int start, int end)
{
	int		str_len;
	int		new_len;
	char	*res;

	if (!str || !new || end < start || start < 0 || end < 0)
		return (NULL);
	str_len = ft_strlen(str);
	new_len = ft_strlen(new);
	res = (char *)malloc(str_len - (end - start) + new_len + 1);
	if (!res)
		return (NULL);
	ft_memmove(res, str, start);
	ft_memmove(res + start, new, new_len);
	ft_memmove(res + start + new_len, str + end, str_len - end);
	res[str_len - (end - start) + new_len] = '\0';
	return (res);
}
