/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:01:54 by seyun             #+#    #+#             */
/*   Updated: 2021/10/28 21:53:57 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h> // strlen
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // pipe
#include "../Libft/libft.h"
#include <sys/wait.h>
# define P_READ 0
# define P_WRITE 1

void	child_command()
{
	char	*path;
	int		res;	
	
	res = read(0, path, strlen(path));
	if (!res)
		exit(1);
	write(1, path, ft_strlen(path));
	return ;
}

void	proc_child(int pipe[2])
{
	close(pipe[P_WRITE]);
	dup2(pipe[P_READ], 0);
	printf("here is child process\n");
	close(pipe[P_READ]);
	child_command();
}

void	parent_command()
{
	return ;
}

void	proc_parent(int pipe[2], int pid, char **args, char **envp)
{
	
	close(pipe[P_READ]);
	dup2(pipe[P_WRITE], 0);
	close(pipe[P_WRITE]);
	find_path(envp, 
	if (waitpid(pid, NULL, 0) == -1)
		exit(1);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];
	char	**args;
	int		i;


	if (pipe(fd) == -1)
		return (1);
	args = (char **)malloc(argc * sizeof(char *));
	if (!args)
		return (0);
	args[argc] = NULL;
	i = -1;
	while (++i < argc -1)
		args[i] = argv[i + 1];
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
		proc_parent(fd, pid, args, envp);
	return (0);
}


