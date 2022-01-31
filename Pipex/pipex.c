/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:01:54 by seyun             #+#    #+#             */
/*   Updated: 2022/01/31 14:15:27 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	std_out(t_input *info)
{
	int	fd;

	fd = open(info->argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit(1);
	dup2(fd, 1);
	close(fd);
}

void	cmd2(int *fd, t_input *info)
{
	char	*path;
	char	**argv;

	close(fd[P_WRITE]);
	dup2(fd[P_READ], 0);
	std_out(info);
	close(fd[P_READ]);
	path = make_cmd(info, 3);
	argv = ft_split(info->argv[3], ' ');
	if (-1 == execve(path, argv, NULL))
	{	
		ft_strexit("ERROR");
	}
}

void	std_in(t_input *info)
{
	int	fd;

	fd = open(info->argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	dup2(fd, 0);
	close(fd);
}

void	cmd1(int *fd, t_input *info)
{
	char	*path;
	char	**argv;

	close(fd[P_READ]);
	std_in(info);
	dup2(fd[P_WRITE], 1);
	close(fd[P_WRITE]);
	path = make_cmd(info, 2);
	argv = ft_split(info->argv[2], ' ');
	if (-1 == execve(path, argv, NULL))
	{	
		ft_strexit("ERROR");
	}
}

void	pipex(t_input *info)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == 0)
		cmd1(fd, info);
	else
	{
		waitpid(pid, 0, WNOHANG);
		cmd2(fd, info);
		exit(1);
	}
	exit(1);
}
