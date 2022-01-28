/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:42:36 by seyun             #+#    #+#             */
/*   Updated: 2022/01/28 22:25:26 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <termios.h>

void	SIG_handler(int sig)
{
	printf("bye\n");
	exit(0);
}

int main(void)
{
	char *line;
	int errono = 0;
	char *error_message; 

	line = NULL;
	if (signal(SIGINT, SIG_handler) == SIG_ERR)
		printf("errexit\n");
	while (1)
	{
		line = readline("prompt: ");
		if (line)
			printf("%s\n", line);
		if (strncmp(line, "exit", 4) == 0)
			exit(0);
		add_history(line);
		free(line);
	}
	return (0);
}

