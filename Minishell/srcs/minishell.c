/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:52:35 by hoylee            #+#    #+#             */
/*   Updated: 2022/03/07 21:04:25 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "../includes/minishell.h"

int	g_exit_status = 0;

int ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

void	pipe_while(char *line, int *i, int *flag)
{
	if (line[*i] == '|')
	{
		*flag = 1;
		while (ft_isspace(line[++(*i)]) == 1)
		{
			if (line[*i] == '\0')
				;
		}
	}
	else
	{
		*flag = 0;
		(*i)++;
	}
}

int		pipe_error(char *line)
{
	int i;
	int flag = 0;

	i = 0;
	if (line[i] == '|')
	{	
		g_exit_status = 258;
		return(1);
	}
	while (line[i] != '\0')
		pipe_while(line, &i, &flag);
	if (flag == 1)
	{	
		g_exit_status = 258;
		return (1);
	}
	return (0);
}

int				main(int argc, char *argv[], char *envp[])
{
	char		*line;
	t_cmd		*cmd_list;
	char		**cpenv;

	dup2(STDIN, 100);
	dup2(STDOUT, 101);
	argc = 1;
	cpenv = copy_envp(envp);
	set_signal();
	while ((line = readline("minishell $ ")))
	{
		if (*line != '\0' && !check_whitespace(line))
		{
			add_history(line);
			if (pipe_error(line) == 1)
				error_write("minishell: syntax error near unexpected token '%s'\n", "|", 0);
			else if (ft_strncmp(line, "export \"\"", 9) == 0)
				error_write("minishell: %s: `%s': not a valid identifer\n", "export", "");
			else
			{
				parse(&cmd_list, line, cpenv);
				g_exit_status= exec(cmd_list, argv, &cpenv);
				free_list(cmd_list);
			}
		}
		free(line);
	}
	ft_putstr_fd("\x1b[1A", STDOUT);
	ft_putstr_fd("\033[12C", STDOUT);
	ft_putstr_fd("exit\n", STDOUT);
	return (0);
}
