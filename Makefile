NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS =	src/push_swap/main.c \
		src/push_swap/error_manager.c \
		src/push_swap/ft_split.c \
		src/push_swap/init_stack.c \
		src/push_swap/set_stacks.c \
		src/push_swap/sort_stack.c \
		src/push_swap/utils.c \
		src/push_swap/move.c \
		src/push_swap/ft_printf1.c \
		src/push_swap/ft_printf2.c \
		src/commands/push.c \
		src/commands/reverse_rotate.c \
		src/commands/rotate.c \
		src/commands/swap.c
OBJS = $(SRCS:.c=.o)

all: obj $(NAME)

obj/%.o: src/%.c include/push_swap.h
	@$(CC) $(CFLAGS) -g3 -c $< -o $@

$(NAME): $(OBJS) include/push_swap.h
	@$(CC) $(CFLAGS) -g3 -o $@ $^
	@mv ${OBJS} obj/

obj:
	@mkdir -p obj

clean:
	$(RM) obj

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re