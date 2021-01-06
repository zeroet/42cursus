/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:33:56 by seyun             #+#    #+#             */
/*   Updated: 2021/01/06 13:43:28 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char buf[BUFF_SIZE + 1];
	int		size;

	if ((fd < 0) || (line == 0) || (BUFF_SIZE < 0))
		return (-1);
	*line = 0;
	while (0 < (size = read(fd, buf, BUFF_SIZE)))
	{
		/*find \n and split */
		if (0 < (find(buf)))
			*line = split_line(buf);/*line * ? */

		
