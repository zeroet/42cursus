TARGET = push_swap

CC = gcc
CFLAG = -Wall -Werror -Wextra
RM = -rm -rf

INCS_DIR = ./includes/
SRCS_DIR = ./srcs/
OBJS_DIR = ./objs/

SRC = checker.c \
	  ft_ra.c \
	  ft_sa.c \
	  glob_utlies.c \
	  main.c \
	  math.c \
	  stack_utiles.c \
	  ft_rra.c \
	  descend_stack.c \
	  ft_pa.c \
	  sort_a.c \
	  sort_b.c \
	  pivot.c \
	  init_function.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC))
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -I $(INCS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

all : $(TARGET)

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(TARGET)

re : clean all

bonus :

.PHONY : all clean fclean re bonus
