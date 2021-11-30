SERVER = server
CLIENT = client

SRCS_SERVER = server.c \
			  utile.c

SRCS_CLIENT = client.c \
			  utile.c

OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : ${SERVER} ${CLIENT}

${SERVER}: ${OBJS_SERVER}
	${CC} ${CFLAGS} ${OBJS_SERVER} -o ${SERVER} -I.

${CLIENT}: ${OBJS_CLIENT}
	${CC} ${CFLAGS} ${OBJS_CLIENT} -o ${CLIENT} -I.

clean:
	${RM} ${OBJS_SERVER}
	${RM} ${OBJS_CLIENT}

fclean: clean
	${RM} ${SERVER}
	${RM} ${CLIENT}

re: fclean all

.PHONY: clean fclean re all
