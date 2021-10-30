TARGET = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = pipex.h
RM = rm -rf

SRC = pipex.c \
	  utiles.c

OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(TARGET)

re : fclean all
