/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:04:18 by seyun             #+#    #+#             */
/*   Updated: 2021/11/29 16:55:06 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_strexit(char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
	exit(0);
}

void	bit_signal(int pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if ((c >> bit & 1) == 0)
			kill(pid, SIGUSR1);
		else if ((c >> bit & 1) == 1)
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	send_signal(int pid, char *str)
{
	while (*str)
		bit_signal(pid, *str++);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_strexit("Error! Need to write as : ./client [Server PID] [Message]");
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_strexit("Pid Error!");
	send_signal(pid, argv[2]);
	return (0);
}
