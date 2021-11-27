NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = pipex.h
RM = rm -f

SRCS = pipex.c \
	  utiles.c \
	  utiles2.c \
	  main.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -I $(HEADER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
