NAME	= push_swap
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -rf
SRCS	=	src/push_swap.c src/error.c src/put_in_list.c
OBJS	=	${SRCS:.c=.o}

all : libft ${NAME}

%.o:	%.c include/push_swap.h
	@${CC} ${CFLAGS} -g3 -Ilibft/ -c $< -o $@

${NAME}:	${OBJS} include/push_swap.h
	${CC} ${CFLAGS} -g3  -o $@ $^ -Llibft/ -lft

fclean : clean
	${RM} ${NAME}

clean :
	${RM} src/*.o
	${RM} libft/obj
	${RM} libft/libft.a
	${RM} push_swap

re : fclean all

libft:
	@mkdir -p libft/obj/
	@make -s -C libft/

.PHONY: all clean fclean re libft