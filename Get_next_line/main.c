/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:10:20 by seyun             #+#    #+#             */
/*   Updated: 2021/01/09 11:35:39 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd;
	char **line = NULL;

	
	while (0 < (fd = open("txt.txt", O_RDONLY)))
	{
		if (fd == EOF)
			break ;
		get_next_line(fd, line);
		printf ("%s\n", *line);
	}
	close(fd);
}

