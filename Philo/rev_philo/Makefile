# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytak <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 12:51:34 by ytak              #+#    #+#              #
#    Updated: 2022/01/19 18:29:19 by seyun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

#PHI_BONUS	= philo_bonus

SRCS = main.c \
	   ft_thread_checker.c \
	   ft_create_thread.c \
	   ft_philo_eat.c \
	   ft_philo_eat_all.c \
	   ft_sleep.c \
	   ft_struct_init.c \
	   ft_mutex_init.c \
	   ft_utils.c \
#SRCS_BONUS =
OBJS 		= ${SRCS:.c=.o}
#OBJS_B		= ${SRCS_BONUS:.c=.o}

#CC			= gcc
CC			= gcc -g3 -fsanitize=address
#CC			= gcc -g3 -fsanitize=thread
CFLAGS		= -Wall -Wextra -Werror -pthread
RM			= rm -f
NAME		= philo

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS)

#$(PHI_BONUS):${OBJS_B}
#			${CC} ${CFLAGS} -o ${PHI_BONUS} ${OBJS_B}

bonus:		re $(PHI_BONUS)

clean:
			${RM} ${OBJS}  
#			${RM} ${OBJS_B}

fclean: 	clean
			${RM} ${NAME}
#			${RM} ${PHI_BONUS}

re: 		fclean all

.PHONY:		bonus all clean fclean re
