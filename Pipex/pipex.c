/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:01:54 by seyun             #+#    #+#             */
/*   Updated: 2021/11/26 20:15:35 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd2(int *fd, t_input *info)
{
	printf("cm2\n");
	close(fd[P_WRITE]);
	dup2(fd[P_READ], 1);
	close(fd[P_READ]);
	return ;
}

char *get_path(t_input *info)
{
	char *res;
	int i;

	i = 0;
	res = NULL;
	while (info->envp[i])
	{
		if(!(ft_memcmp(info->envp[i], "PATH=", 4)))
		{	
			res = info->envp[i];
			break ;
		}
		i++;
	}
	return (res);
}

char	*make_cmd1(t_input *info)
{
	char *path;
	char **envp;
	char *cmd1;
	char *res;
	int	mode;
	int i;

	path = get_path(info);
	envp = ft_split(path + 5, ':');
	cmd1 = ft_strjoin("/", info->argv[2]);
	mode = X_OK | F_OK;
	while (envp[i])
	{
		res = ft_strjoin(envp[i], cmd1);
		if (access(res, mode))
		{
			free(envp);
			free(cmd1);
			return (res);
		}
		free(res);
		i++;
	}
	free(cmd1);
	free(envp);
	exit(1);
}

void	std_in(t_input *info)
{
	int fd;
	int ck;

	fd = open(info->argv[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	ck = dup2(fd, 0);
	printf("parent process : stdin file %d  open success\n", ck);
	close(fd);
}

void	cmd1(int *fd, t_input *info)
{
	char *path;
	
	printf("cm1\n");
	std_in(info);
	close(fd[P_READ]);
	dup2(fd[P_WRITE], 0);
	close(fd[P_WRITE]);
	path = make_cmd1(info);
}

void	pipex(t_input *info)
{
	int fd[2];
	pid_t pid;

	printf("fork run\n");
	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
		cmd1(fd, info);
	else
	{
		waitpid(pid, 0, 0);
		cmd2(fd, info);
	}
	exit(1);
}

t_input	*init_info(int argc, char **argv, char **envp)
{
	t_input	*info;
	
	info = (t_input *)malloc(sizeof(t_input));
	if (!info)
		return (NULL);
	info->argc = argc;
	info->argv = argv;
	info->envp = envp;
	return (info);
}

int	main(int argc, char **argv, char **envp)
{
	t_input *info;

	if (argc != 5)
		exit(1);
	info = init_info(argc, argv, envp);
	printf("info success\n");
	pipex(info);
	free(info);
	return (0);
}

