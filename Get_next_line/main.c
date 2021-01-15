/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:10:20 by seyun             #+#    #+#             */
/*   Updated: 2021/01/15 14:35:41 by seyun            ###   ########.fr       */
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
	fd = open("txt.txt", O_RDONLY);
	printf("%d\n", get_next_line(3, line));
	printf("%d\n", get_next_line(3, line));
	printf("%d\n", get_next_line(3, line));
	printf("%d\n", get_next_line(3, line));
	close(fd);
	return (0);
}

