# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flegg <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 18:31:27 by flegg             #+#    #+#              #
#    Updated: 2021/09/17 21:39:28 by flegg            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCDIR	=	src/
OBJDIR	=	obj/
INCDIR	=	include/

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -Ofast -MMD -I $(INCDIR)
CFLAGS_DB	=	-Wall -Werror -Wextra -g -MMD -I $(INCDIR)

SRC		=	ft_strmapi.c \
			ft_itoa.c \
		 	ft_split.c \
			ft_strtrim.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_memset.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_memccpy.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstmap.c \
			ft_lstiter.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstadd_back.c \
			ft_lstlast.c \
			ft_lstsize.c \
			ft_lstadd_front.c \
			ft_lstnew.c \
			get_next_line.c \
			get_next_line_utils.c \
			mem_manager.c \
			mem_manager_utils.c \
			ft_strchrpos.c

SRCFULL	=	$(addprefix $(SRCDIR), $(SRC))
OBJ	=	$(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCFULL))

.PHONY: all debug clean fclean re

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

-include $(OBJ:.o=.d)
$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJ)
	ar rc $(NAME) $(OBJ)

debug: CFLAGS=$(CFLAGS_DB)
debug: $(OBJDIR) $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
