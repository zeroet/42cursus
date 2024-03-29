/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:33:56 by seyun             #+#    #+#             */
/*   Updated: 2021/12/30 17:57:55 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				find(char *backup)
{
	int			i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				split_line(char **backup, char **line, int end_index)
{
	int			len;
	char		*tmp;

	(*backup)[end_index] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + end_index + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	tmp = ft_strdup(*backup + end_index + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int				all_return(char **backup, char **line, int size)
{
	int			end_index;

	if (size < 0)
		return (-1);
	if (*backup && (0 <= (end_index = find(*backup))))
		return (split_line(backup, line, end_index));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup[OPEN_MAX];
	int			end_index;
	int			size;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while (0 < (size = read(fd, buf, BUFFER_SIZE)))
	{
		buf[size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if (0 <= (end_index = find(backup[fd])))
			return (split_line(&backup[fd], line, end_index));
	}
	return (all_return(&backup[fd], line, size));
}
