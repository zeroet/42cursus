/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:09:47 by seyun             #+#    #+#             */
/*   Updated: 2021/11/29 16:27:21 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	static int	code;
	static int	count;

	count += 1;
	code = code << 1;
	if (signal == SIGUSR2)
		code += 1;
	if (count == 8)
	{
		ft_putchar(code);
		code = 0;
		count = 0;
	}
}

int	main(void)
{
	char	*pid;
	int		get_pid;

	get_pid = getpid();
	pid = ft_itoa(get_pid);
	ft_putstr(pid);
	ft_putchar('\n');
	free(pid);
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
