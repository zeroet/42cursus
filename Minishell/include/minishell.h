#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/include/libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# include <readline/readline.h>
# include <readline/history.h>

# define OPERATOR_COUNT 6
# define PATH_BUF_LEN 256
# define PATH_BUF_LEN_EXTENSION 1024

typedef struct s_redirect
{
	int		fd_to_change;
	int		this_redirect_fd;
	int		flags;
	int		mode;
	char	*path;
}			t_redirect;

typedef struct s_cmd
{
	t_list	*redirects;
	char	**argv;
	pid_t	pid;
}			t_cmd;

typedef struct s_parser_data
{
	t_list	*lst_cmd;
	t_cmd	*tmp_cmd;
	t_list	*cmds_lst;

}			t_parser_data;

typedef struct s_workers_elem
{
	char	str[3];
	int		(*worker)(t_parser_data *, t_list **);
}			t_workers_elem;

typedef struct s_shell
{
	int				cmd_count;
	t_cmd			**cmd;
	char			**envp;
	pid_t			heredoc_pid;
	int				heredoc_exit_status;
	int				last_exit_code;
	t_workers_elem	parser_operators[OPERATOR_COUNT];
}					t_shell;

extern t_shell	g_sh;

/* builtins */
int			pwd(int argc, char **argv);
int			echo(int argc, char **argv);
int			cd(int argc, char **argv);
int			env(int argc, char **argv);
int			exit_builtin(int argc, char **argv);
int			export(int argc, char **argv);
int			unset(int argc, char **argv);
int			ft_error(char *err, int exit_code, char *name, char *command);
char		*my_getcwd(char *buf);
int			ft_strcmp(const char *s1, const char *s2);
int			export_endl_worker(char *str, int i);
int			export_equal_worker(char *str, int i);
int			export_plus_worker(char *str, int i);

/* cmd_exec */
void		child_worker(int i);
int			close_and_wait(pid_t pid);
int			cmdline_exec(void);
void		*get_builtin_worker(char *cmd_name);
char		*get_full_path(char *path, char **envp);
int			is_cmd_error(char *path, int file_flag);

/* env */
char		**add_new_env_to_end(char ***env, char *name, char *new_val);
char		*get_envp_by_name(char **env, char *name, int name_len);
char		**make_env(char *env[]);
char		*new_env_line(char *name, char *val);
char		**remove_from_env(char ***env, char *name);
char		*set_envp_by_name(char ***env, char *name, char *new_val);
int			update_shlvl_env(void);

/* errors */
int			error_free(int ret, const char *perror_str);
void		if_error(int is_true, const char *perror_str, int ret);
int			print_perror(int ret, const char *perror_str);

/* free */
void		free_all_globals(void);
void		free_cmd_arr(void);

/* parser */
int			check_and_remove_quotes(char *str);
int			check_for_data_arg(t_list *lst_item, int pipe_flag);
t_cmd		*new_cmd(void);
int			parser(t_list **lst);
int			parser_default(t_parser_data *pdata, t_list **param);
int			parser_heredoc(t_parser_data *pdata, t_list **param);
int			parser_pipe(t_parser_data *pdata, t_list **param);
int			parser_stdin(t_parser_data *pdata, t_list **param);
int			parser_stdout(t_parser_data *pdata, t_list **param);
int			parser_stdout_append(t_parser_data *pdata, t_list **param);

/* redirects */
void		apply_redirects(int i);
t_redirect	*new_redirect_data(char *path);
void		add_redirect(t_cmd *cmd_ptr, t_redirect *data);
void		add_redirect_front(t_cmd *cmd_ptr, t_redirect *data);
void		close_redirects(t_list *lst);
void		free_redirect_data(void *param);

/* signals */
void		sigint_handler_cmd(int num);
void		sigint_handler_heredoc(int num);
void		sigint_handler_prompt(int num);
void		sigquit_handler_cmd(int num);
void		sigquit_handler_heredoc(int num);
void		sigquit_handler_prompt(int num);

/* tokenizer */
int			add_arg_to_lst(char **p, char **t, t_list **lst);
int			add_special(char **p, char **t, t_list **lst, char *special);
int			add_to_lst(char *new_str, t_list **lst);
int			dollar_replace(char **str);
int			dollar_name_len(char *i);
int			dollar_worker(char **str, int *i);
t_list		*tokenizer(char **s);

/* utils */
void		char_array_free(char **p);
void		do_nothing(void *var);
t_list		*ft_lstreverse(t_list *old);
int			is_space(char c);
void		*lst_to_arr(t_list	*lst, size_t element_size, int direction);
int			my_access(char *path, int flag);
int			my_strcmp(const char *s1, const char *s2);
int			my_strncmp(const char *s1, const char *s2, int n);
int			ptr_arr_len(void **arr);
char		*strdup_insert(char *str, char *new, int start, int end);

/* main */
void		init_parser_operators(void);

void		rl_replace_line(const char *text, int clear_undo);

#endif
