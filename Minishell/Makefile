# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flegg <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 16:02:20 by flegg             #+#    #+#              #
#    Updated: 2022/07/08 20:24:57 by seyun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

SRCDIR	=	src/
OBJDIR	=	obj/
INCDIR	=	include/

LIBFT_DIR	=	libft
LIBFT_A		=	$(LIBFT_DIR)/libft.a
RL_FLAGS	=	-lreadline

CC			=	gcc
OFLAGS		=	-Wall -Werror -Wextra -Ofast -MMD -I $(INCDIR)
OFLAGS_DB	=	-Wall -Werror -Wextra -g -MMD -I $(INCDIR)
BFLAGS		=	-Wall -Werror -Wextra -Ofast $(RL_FLAGS)
BFLAGS_DB	=	-Wall -Werror -Wextra -g $(RL_FLAGS)

SRC			=	main.c \
				builtins/cd.c \
				builtins/echo.c \
				builtins/env.c \
				builtins/exit.c \
				builtins/export.c \
				builtins/export_workers.c \
				builtins/pwd.c \
				builtins/unset.c \
				builtins/common_utils.c \
				cmd_exec/child_worker.c \
				cmd_exec/close_and_wait.c \
				cmd_exec/cmdline_exec.c \
				cmd_exec/get_builtin_worker.c \
				cmd_exec/get_full_path.c \
				cmd_exec/is_cmd_error.c \
				env/add_new_env_to_end.c \
				env/get_envp_by_name.c \
				env/make_env.c \
				env/new_env_line.c \
				env/remove_from_env.c \
				env/set_envp_by_name.c \
				env/update_shlvl_env.c \
				errors/error_free.c \
				errors/if_error.c \
				errors/print_perror.c \
				free/free_all_globals.c \
				free/free_cmd_arr.c \
				parser/check_and_remove_quotes.c \
				parser/check_for_data_arg.c \
				parser/new_cmd.c \
				parser/parser.c \
				parser/parser_default.c \
				parser/parser_heredoc.c \
				parser/parser_pipe.c \
				parser/parser_stdin.c \
				parser/parser_stdout.c \
				parser/parser_stdout_append.c \
				redirects/apply_redirects.c \
				redirects/redirects.c \
				signals/sigint_handler_cmd.c \
				signals/sigint_handler_heredoc.c \
				signals/sigint_handler_prompt.c \
				signals/sigquit_handler_cmd.c \
				signals/sigquit_handler_heredoc.c \
				signals/sigquit_handler_prompt.c \
				tokenizer/add_arg_to_lst.c \
				tokenizer/add_special.c \
				tokenizer/add_to_lst.c \
				tokenizer/dollar_replace.c \
				tokenizer/dollar_worker.c \
				tokenizer/tokenizer.c \
				utils/char_array_free.c \
				utils/do_nothing.c \
				utils/ft_lstreverse.c \
				utils/is_space.c \
				utils/lst_to_arr.c \
				utils/my_access.c \
				utils/my_strcmp.c \
				utils/ptr_arr_len.c \
				utils/strdup_insert.c

SRCFULL	=	$(addprefix $(SRCDIR), $(SRC))
OBJS	=	$(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCFULL))

.PHONY: all debug clean fclean re

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)builtins
	mkdir -p $(OBJDIR)cmd_exec
	mkdir -p $(OBJDIR)env
	mkdir -p $(OBJDIR)errors
	mkdir -p $(OBJDIR)free
	mkdir -p $(OBJDIR)parser
	mkdir -p $(OBJDIR)redirects
	mkdir -p $(OBJDIR)signals
	mkdir -p $(OBJDIR)tokenizer
	mkdir -p $(OBJDIR)utils

-include $(OBJS:.o=.d)
$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(OFLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)
	$(MAKE) -C libft
	$(CC) $(BFLAGS) $(OBJS) libft/libft.a -o $(NAME) -lreadline
debug: OFLAGS=$(OFLAGS_DB)
debug: BFLAGS=$(BFLAGS_DB)
debug: $(OBJDIR) $(OBJS)
	$(MAKE) debug -C libft
	$(CC) $(BFLAGS) $(OBJS) libft/libft.a -o $(NAME)

libclean:
	$(MAKE) clean -C libft

libfclean:
	$(MAKE) fclean -C libft

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

ffclean: libfclean fclean

re: fclean all
