NAME = server

NAME1 = client

printf = ft_printf/libftprintf.a

CC = cc

CFLAGS =  -Wall -Wextra -Werror

SRC= server.c\
	 error.c\
	 
SRC_1= client.c\
	   ft_atoi.c\
	   error.c\

OBG = ${SRC:.c=.o}
OBG_1 = ${SRC_1:.c=.o}

all : ${NAME} ${NAME1} ${printf}

${NAME} : ${OBG} ${printf} minitalk.h
	${CC} ${printf} ${OBG} -o $@

${NAME1} : ${OBG_1} ${printf} minitalk.h
	${CC} ${printf} ${OBG_1} -o $@

${printf} : ft_printf/ft_printf.h
	@${MAKE} -C ${p_file}

%.o : %.c minitalk.h
	cc ${CFLAGS} -c $< -o $@

clean :
	rm -rf ${OBG} ${OBG_1}
	@${MAKE} clean -C ft_printf

fclean : clean
	rm -rf ${NAME} ${NAME1}
	@${MAKE} fclean -C ft_printf