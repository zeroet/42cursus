
# =============================================================================
# Color Variables
# =============================================================================

BLACK		= 	"\033[0;30m"
GRAY		= 	"\033[1;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
PURPLE		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"
LINE_CLEAR	=	"\x1b[1A\x1b[M"

# =============================================================================
# Command Variables
# =============================================================================

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCS = -I./srcs -I./libft -I./mlx
INCLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Llibft -lft

LIBFT_D = ./libft
LIBFT_A = ./libft/libft.a
LIBFT_M = ./mlx

FILES = cub3d.c \
		01_read_info.c \
		02_validate_info_map.c \
		03_read_map.c \
		04_rearrange_game.c \
		05_run_game.c \
		06_execute_ray.c \
		07_set_background.c \
		08_ray_background.c

SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_D)
	make -C $(LIBFT_M)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(INCLIB)

clean:
	make -C $(LIBFT_D) clean
	make -C $(LIBFT_M) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIBFT_A)

re: fclean all

.PHONY: all clean fclean re
