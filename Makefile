NAME = push_swap
NAME_BONUS = checker/checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS =	src/commands/push.c \
		src/commands/reverse_rotate.c \
		src/commands/rotate.c \
		src/commands/swap.c \
		src/libft/ft_printf1.c \
		src/libft/ft_printf2.c \
		src/libft/get_next_line.c \
		src/libft/get_next_line_utils.c \
		src/libft/ft_str.c \
		src/libft/utils.c \
		src/push_swap/main.c \
		src/push_swap/errors_and_free.c \
		src/push_swap/find.c \
		src/push_swap/set_stacks.c \
		src/push_swap/sort_stacks.c \
		src/push_swap/move.c \

SRCS_BONUS =	src/commands/push.c \
				checker/checker.c \
				src/commands/reverse_rotate.c \
				src/commands/rotate.c \
				src/commands/swap.c \
				src/libft/ft_printf1.c \
				src/libft/ft_printf2.c \
				src/libft/get_next_line.c \
				src/libft/get_next_line_utils.c \
				src/libft/ft_str.c \
				src/libft/utils.c \
				src/push_swap/main.c \
				src/push_swap/errors_and_free.c \
				src/push_swap/find.c \
				src/push_swap/set_stacks.c \
				src/push_swap/sort_stacks.c \
				src/push_swap/move.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

%.o: src/%.c include/push_swap.h
	@$(CC) $(CFLAGS) -g3 -c $< -o $@

$(NAME): $(OBJS) include/push_swap.h
	@$(CC) $(CFLAGS) -g3 -o $@ $^

$(NAME_BONUS): $(OBJS_BONUS) include/push_swap.h
	@$(CC) $(CFLAGS) -g3 -o $(NAME_BONUS)

bonus : $(NAME_BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re