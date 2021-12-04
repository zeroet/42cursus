# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytak <ytak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 13:57:20 by ytak              #+#    #+#              #
#    Updated: 2021/08/23 14:36:32 by ytak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_printf_string.c ft_printf_num.c

SRCS_B	= 

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

NAME	= libftprintf.a

RM 		= rm -f

AR		= ar rc

.c.o:
		gcc -Wall -Wextra -Werror -g3 -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
		${AR} ${NAME} ${OBJS}

bonus: 		${OBJS_B}
		${AR} ${NAME} ${OBJS_B}

clean:
		${RM} ${OBJS} ${OBJS_B}

fclean:		clean
		${RM}	${NAME}

re: 		fclean all

.PHONY: 	all bonus clean fclean re
