/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:33:56 by seyun             #+#    #+#             */
/*   Updated: 2021/01/06 17:17:05 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			find(*str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char		*split_line(char *str, int index)
{
	char *res;

	if (!(res = (char *)malloc(index + 1)))
		return (0);

}

int			get_next_line(int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		size;
	static	*backup[OPEN_MAX];
	int		end_index;

	if ((fd < 0) || (line == 0) || (BUFF_SIZE < 0))
		return (-1);
	*line = 0;
	while (0 < (size = read(fd, buf, BUFF_SIZE)))
	{
		buf[size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if (0 < (end_index = find(backup[fd])))
			*line = split_line(backup[fd], end_index);
			
