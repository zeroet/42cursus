/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:01:54 by seyun             #+#    #+#             */
/*   Updated: 2021/11/27 00:38:39 by seyun            ###   ########.fr       */
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
	char *path;

	close(fd[P_WRITE]);
	dup2(fd[P_READ], 1);
	close(fd[P_READ]);
	std_out(info);
	path = make_cmd(info, 3);
	printf("%s \n ", path);
	if (path == NULL)
		printf("ERROR: NULL PATH\n");
	execve(path, info->argv, info->envp);
}

char **get_path(t_input *info)
{
	char **res;
	char	*tmp;
	int i;

	i = 0;
	res = NULL;
	while (info->envp[i])
	{
		if(!(ft_memcmp(info->envp[i], "PATH=", 4)))
		{	
			tmp = info->envp[i];
			res = ft_split(tmp + 5, ':');
			return (res);
		}
		i++;
	}
	return (NULL);
}

char	*make_cmd(t_input *info, int index)
{
	char **envp;
	int	i;
	char *res;
	char *cmd;

	i = 0;
	envp = get_path(info);
	cmd = ft_strjoin("/", info->argv[index]);
	while (envp[i])
	{
		res = ft_strjoin(envp[i], cmd);
		if (access(res, X_OK))
		{
			free(envp);
			free(cmd);
			return (res);
		}
		free(res);
		i++;
	}
	free(cmd);
	free(envp);
	return (NULL);
}

void	std_in(t_input *info)
{
	int fd;

	fd = open(info->argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	dup2(fd, 0);
	close(fd);
}

void	cmd1(int *fd, t_input *info)
{
	char *path;
	
	close(fd[P_READ]);
	dup2(fd[P_WRITE], 0);
	close(fd[P_WRITE]);
	std_in(info);
	path = make_cmd(info, 2);
	printf("%s\n", path);
	if (path == NULL)
		printf("ERROR: NULL PATH\n");
	execve(path, info->argv, info->envp);
}

void	pipex(t_input *info)
{
	int fd[2];
	pid_t pid;

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
	pipex(info);
	free(info);
	return (0);
	}

