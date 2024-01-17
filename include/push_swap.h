/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:34:19 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/17 14:03:15 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*------------------------ INCLUDES ------------------------*/
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

/*------------------------ GLOBAL VAR ------------------------*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*------------------------ STRUCTURE ------------------------*/
typedef struct s_stack
{
	int				nb;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

/*------------------------ COMMANDS ------------------------*/
void	sa(t_stack **a, bool checker);
void	sb(t_stack **b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);
void	pa(t_stack **b, t_stack **a, bool checker);
void	pb(t_stack **a, t_stack **b, bool checker);
void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);
void	rra(t_stack **a, bool checker);
void	rrb(t_stack **b, bool checker);
void	rrr(t_stack **a, t_stack **b, bool checker);

/*-------------------------- LIBFT --------------------------*/
// ft_printf
int		ft_printf(const char *str, ...);
void	ft_print_ptr(unsigned long long addr, size_t *len);
void	ft_print_nbr(int nb, size_t *len);
void	ft_print_hexa(unsigned int nb, char *base, size_t *len);
void	ft_print_unsigned(unsigned int nb, size_t *len);
void	ft_print_char(int c, size_t *len);
void	ft_print_str(char *str, size_t *len);
void	len_var(va_list args, const char c, size_t *len);
// get_next_line
char	*get_next_line(int fd);
size_t	check_newline(char *str);
size_t	ft_strlen_gnl(char *str);
char	*str_init(char	*line);
// ft_split
char	**ft_split(char *str, char sep);
char	*ft_strncpy(char *s1, char *s2, int n);
// ft_strjoin
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(char *s1, char *s2);
// utils
bool	add_node(t_stack **stack, int n);
long	ft_atol(char *argv);
void	ft_putstr(char *str);

/*------------------------ FUNCTIONS ------------------------*/
int		main(int argc, char **argv);
void	check_init_a(t_stack **stack, char **argv, bool tab2d);

/*---------------------- ERROR MANAGER ----------------------*/
bool	error_syntax(char *argv);
bool	error_dobble(t_stack **stack, int n);
void	free2d(char **str);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **stack, char **argv, char *error_msg, bool tab2d);

/*------------------------ SET STACK ------------------------*/
void	set_index_median(t_stack *stack);
void	smaller_closest(t_stack *src, t_stack **target_stack);
void	bigger_closest(t_stack *src, t_stack **target_stack);
void	set_stacks(t_stack **a, t_stack **b, char which_stack);
void	set_push_cost(t_stack *src, t_stack **target_stack, int index_last);
void	set_cheapest(t_stack **stack);

/*------------------------ SORT STACK ------------------------*/
void	sort_three(t_stack	**stack);
bool	stack_sorted(t_stack *stack);
int		size_stack(t_stack *stack);
void	sort_stack(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);

/*------------------------ MOVE NODE ------------------------*/
void	move_both(t_stack **a, t_stack **b, t_stack *src, bool above_median);
void	move_one(t_stack **stack, t_stack *src, char witch_stack);
void	move(t_stack **src, t_stack **dst, char direction);

/*------------------------ FIND NODE ------------------------*/
t_stack	*find_last(t_stack **stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_cheapest(t_stack **stack);

/*------------------------- CHECKER -------------------------*/
int		ft_strcmp(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
void	exit_programm(t_stack **a, t_stack **b, char *verif);
void	commands(t_stack **a, t_stack **b, char *command);
void	do_commands(t_stack **a, t_stack **b);

// void	move_a_to_b(t_stack **a, t_stack **b);
// void	move_b_to_a(t_stack **a, t_stack **b);
// void	display_stack(t_stack *stack);
#endif
