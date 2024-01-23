NAME = push_swap
NAME_BONUS = checker
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =	commands/push.c \
		commands/reverse_rotate.c \
		commands/rotate.c \
		commands/swap.c \
		\
		libft/ft_printf1.c \
		libft/ft_printf2.c \
		libft/get_next_line.c \
		libft/get_next_line_utils.c \
		libft/ft_str.c \
		libft/utils.c \
		\
		src/main.c \
		src/check_init_a.c \
		src/errors.c \
		src/find.c \
		src/set_stacks.c \
		src/sort_stacks.c \
		src/move.c \

SRCS_BONUS =	\
		commands/push.c \
		commands/reverse_rotate.c \
		commands/rotate.c \
		commands/swap.c \
		\
		libft/ft_printf1.c \
		libft/ft_printf2.c \
		libft/get_next_line.c \
		libft/get_next_line_utils.c \
		libft/ft_str.c \
		libft/utils.c \
		\
		src/checker.c \
		src/check_init_a.c \
		src/errors.c \
		src/find.c \
		src/set_stacks.c \
		src/sort_stacks.c \
		src/move.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

.c.o:	include/push_swap.h
	@gcc ${CFLAGS} -g3 -c $< -o $@

$(NAME): $(OBJS) include/push_swap.h
	@gcc $(CFLAGS) -g3 -o $@ $^

$(NAME_BONUS): $(OBJS_BONUS) include/push_swap.h
	@gcc $(CFLAGS) -g3 -o $@ $^

bonus : $(NAME_BONUS)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus