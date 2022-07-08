/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:12:44 by flegg             #+#    #+#             */
/*   Updated: 2021/09/10 17:12:44 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_error(char *err, int exit_code, char *name, char *command)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	if (command)
	{
		ft_putstr_fd("`", 2);
		ft_putstr_fd(command, 2);
		ft_putstr_fd("': ", 2);
	}
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n", 2);
	return (exit_code);
}

char	*my_getcwd(char *buf)
{
	char	*tmp;

	if (buf == NULL)
		buf = malloc(PATH_BUF_LEN);
	if (buf == NULL)
		return (NULL);
	tmp = getcwd(buf, PATH_BUF_LEN);
	if (tmp == NULL)
	{
		free(buf);
		if (errno == ERANGE)
		{
			buf = malloc(PATH_BUF_LEN + PATH_BUF_LEN_EXTENSION);
			if (buf == NULL)
				return (NULL);
			tmp = getcwd(buf, PATH_BUF_LEN);
			if (tmp == NULL)
				free(buf);
		}
		else
			return (NULL);
	}
	return (tmp);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i]
		   && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
