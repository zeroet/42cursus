/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:33:56 by seyun             #+#    #+#             */
/*   Updated: 2021/01/08 13:35:09 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			find(*backup)
{
	int		i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char		*split_line(char **backup, char **line, int end_index)
{
	int		len;
	char	*tmp;

	*backup[end_index] = '\0';
	*line = strdup(*backup);
	len = strlen(*backup + end_index + 1)
	if (len == 0)
	{
		free(*backup);
		return (1);
	}
	tmp = strdup(*backup + end_index + 1);
	free(*backup);
	*backup = 0;
	*backup = tmp;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	static	*backup[OPEN_MAX];
	int		end_index;
	int		size;

	if ((fd < 0) || (line == 0) || (BUFF_SIZE < 0))
		return (-1);
	*line = 0;
	while (0 < (size = read(fd, buf, BUFF_SIZE)))
	{
		buf[size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if (0 =< (end_index = find(backup[fd])))
			return (split_line(&backup[fd], line, end_index);
	}
	return (0);
}
