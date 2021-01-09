/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:10:20 by seyun             #+#    #+#             */
/*   Updated: 2021/01/09 12:27:39 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>

#define LINE_SIZE 100

int main()
{
	int fd;
	char **line;

	line = (char **)malloc(LINE_SIZE * sizeof(char*));
	while (0 <= (fd = open("txt.txt", O_RDONLY)))
	{
		if (fd == EOF)
			break ;
		get_next_line(fd, line);
		printf ("%s\n", *line);
	}
	close(fd);
	return (0);
}

