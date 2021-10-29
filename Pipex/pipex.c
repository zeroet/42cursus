/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:01:54 by seyun             #+#    #+#             */
/*   Updated: 2021/10/29 18:19:36 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_command()
{
	return ;
}

void	proc_child()
{
	printf("here is child process\n");
	child_command();
}

void	parent_command()
{
	return ;
}

char	*find_path(char **envp, char **args)
{
	char	*tmp;
	//char	**res;
	int		i;

	while (envp != '\0')
	{
		if (!(ft_memcmp(envp[i], "PATH=", 5)))
		{
			tmp = envp[i];
			printf("%s\n", tmp);
			return (tmp);
		}
	}
	return (0);
}

void	proc_parent(int pid, char **args, char **envp)
{
	int fd;

	fd = open(args[1], O_RDONLY);
	if (fd == -1)
		exit (1);
	printf("open succes\n");
	find_path(envp, args);
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
		exit (1);
	}
	if (pid == 0)
	{	
		close(fd[P_WRITE]);
		dup2(fd[P_READ], 0);
		close(fd[P_READ]);
		proc_child();
	}
	else
	{
		close(fd[P_READ]);
		dup2(fd[P_WRITE], 1);
		close(fd[P_WRITE]);
		proc_parent(pid, args, envp);
	}
	return (0);
}


