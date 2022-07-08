/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:04:42 by flegg             #+#    #+#             */
/*   Updated: 2022/07/08 21:33:48 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_shell g_sh;

void	init_parser_operators(void)
{
	ft_memmove(g_sh.parser_operators[0].str, "", 2);
	g_sh.parser_operators[0].worker = parser_default;
	ft_memmove(g_sh.parser_operators[1].str, "|", 2);
	g_sh.parser_operators[1].worker = parser_pipe;
	ft_memmove(g_sh.parser_operators[2].str, "<", 2);
	g_sh.parser_operators[2].worker = parser_stdin;
	ft_memmove(g_sh.parser_operators[3].str, "<<", 3);
	g_sh.parser_operators[3].worker = parser_heredoc;
	ft_memmove(g_sh.parser_operators[4].str, ">", 2);
	g_sh.parser_operators[4].worker = parser_stdout;
	ft_memmove(g_sh.parser_operators[5].str, ">>", 3);
	g_sh.parser_operators[5].worker = parser_stdout_append;
}

int	init(char const *env[])
{
	rl_outstream = stderr;
	g_sh.cmd = NULL;
	g_sh.cmd_count = 0;
	g_sh.last_exit_code = 0;
	g_sh.heredoc_pid = 0;
	g_sh.envp = make_env((char **)env);
	if (g_sh.envp == NULL)
		return (-1);
	if (update_shlvl_env() == -1)
		return (-1);
	init_parser_operators();
	return (0);
}

static void	signals_free_readline_tokenizer(t_list **lst)
{
	char	*line;

	signal(SIGINT, sigint_handler_prompt);
	signal(SIGQUIT, sigquit_handler_prompt);
	free_cmd_arr();
	line = readline("minishell$ ");
	if (line == NULL)
	{
		if ((write(2, "exit\n", 5)) == -1)
				exit(1);
		free_all_globals();
		exit(g_sh.last_exit_code);
	}
	if (line[0] != 0)
		add_history(line);
	*lst = tokenizer(&line);
	free(line);
}

static void	main_loop(void)
{
	t_list	*lst;
	int		res;

	res = 0;
	while (1)
	{
		signals_free_readline_tokenizer(&lst);
		if (lst == NULL)
			continue ;
		res = parser(&lst);
		ft_lstclear(&lst, &free);
		if (res)
		{
			if (res != -1)
			{
				g_sh.last_exit_code = res;
				continue ;
			}
			exit(error_free(1, "fatal error"));
		}
		g_sh.cmd_count = ptr_arr_len((void **)g_sh.cmd);
		cmdline_exec();
		g_sh.cmd_count = 0;
	}
}

int	main(int argc, char *argv[], char const *env[])
{
	(void)argc;
	(void)argv;
	if (init(env) != 0)
		return (error_free(1, "malloc"));
	main_loop();
	return (0);
}
