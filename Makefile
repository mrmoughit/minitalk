NAME = server
NAME1 = client
LIBFTPRINTF = ft_printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = server.c error.c
SRC_1 = client.c ft_atoi.c error.c
OBJ = $(SRC:.c=.o)
OBJ_1 = $(SRC_1:.c=.o)

all: ${NAME} ${NAME1}

${NAME}: ${OBJ} ${LIBFTPRINTF}
	${CC} ${OBJ} -o ${NAME} ${LIBFTPRINTF}

${NAME1}: ${OBJ_1} ${LIBFTPRINTF}
	${CC} ${OBJ_1} -o ${NAME1} ${LIBFTPRINTF}

${LIBFTPRINTF}: ft_printf/ft_printf.h
	${MAKE} -C ft_printf

%.o: %.c minitalk.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ} ${OBJ_1}
	${MAKE} clean -C ft_printf

fclean: clean
	rm -rf ${NAME} ${NAME1}
	${MAKE} fclean -C ft_printf

re: fclean all
