/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:01:54 by seyun             #+#    #+#             */
/*   Updated: 2021/10/28 00:08:58 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h> // strlen
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // pipe
#include <sys/wait.h>
# define P_READ 0
# define P_WRITE 1

void	child_command()
{
	int fd;
	char buffer[1024];
	int res;

	res = read(0, buffer, 1024);
	buffer[res] = '\0';
	write(1, buffer, strlen(buffer));
	return ;
}

void	proc_child(int pipe[2])
{
	int fd;
	int w_fd;
	int r_fd;

	close(pipe[P_WRITE]);
	r_fd = dup2(pipe[P_READ], 1);
	if (r_fd == -1)
		exit(1);
	close(pipe[P_READ]);
	fd = open("read.txt", O_RDONLY);
	if (fd == -1)
		exit(1);
	w_fd = dup2(fd, 0);
	child_command();
	if (w_fd == -1)
		exit(1);
	close(fd);
}

void	parent_command()
{
	int fd;
	int res;
	char buffer[1024];

	res = read(0, buffer, 1024);
	if (res == -1)
		exit(1);
	buffer[res] = '\0';
	write(1, buffer, strlen(buffer));
	return ;
}

void	proc_parent(int pipe[2], int pid)
{
	int	r_fd;
	int	w_fd;
	int fd;

	close(pipe[P_WRITE]);
	r_fd = dup2(pipe[P_READ], 0);
	if (r_fd == -1)
		exit(1);
	fd = open("write.txt", O_WRONLY);
	if (fd == -1)
		exit(1);
	w_fd = dup2(fd, 1);
	close(fd);
	if (w_fd == -1)
		exit(1);
	//if (waitpid(pid, NULL, 0) == -1)
	//	exit(1);
	parent_command();
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		fd[2];

	if ((pipe(fd) == -1))
		return (1);
	pid = fork();
	if (pid == -1)
	{
		close(fd[P_READ]);
		close(fd[P_WRITE]);
		return (1);
	}
	if (pid == 0)
		proc_child(fd);
	else
		proc_parent(fd, pid);
	return (0);
}


