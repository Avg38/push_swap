NAME	= push_swap
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -rf
SRCS	=	src/push_swap.c src/error.c src/put_in_list.c
OBJS	=	${SRCS:.c=.o}

all : ${NAME}

%.o:	%.c include/push_swap.h
	@${CC} ${CFLAGS} -g3 -c $< -o $@

${NAME}:	${OBJS} include/push_swap.h
	${CC} ${CFLAGS} -g3  -o $@ $^ -lft

fclean : clean
	${RM} ${NAME}

clean :
	${RM} src/*.o
	${RM} push_swap

re : fclean all

.PHONY: all clean fclean re