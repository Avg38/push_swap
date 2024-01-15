/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:34:19 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/15 13:49:42 by avialle-         ###   ########.fr       */
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
void	sa(t_stack **stack_a, bool checker);
void	sb(t_stack **stack_b, bool checker);
void	ss(t_stack **stack_a, t_stack **stack_b, bool checker);
void	pa(t_stack **stack_a, t_stack **stack_b, bool checker);
void	pb(t_stack **stack_b, t_stack **stack_a, bool checker);
void	ra(t_stack **stack_a, bool checker);
void	rb(t_stack **stack_b, bool checker);
void	rr(t_stack **stack_a, t_stack **stack_b, bool checker);
void	rra(t_stack **stack_a, bool checker);
void	rrb(t_stack **stack_b, bool checker);
void	rrr(t_stack **stack_a, t_stack **stack_b, bool checker);

/*------------------------ FUNCTIONS ------------------------*/
int		main(int argc, char **argv);
bool	add_node(t_stack **stack, int n);
void	check_init_stack_a(t_stack **stack, char **argv, bool tab2d);
char	*ft_strncpy(char *s1, char *s2, int n);
int		count_words(char *str);
char	**ft_split(char *str);
/*---------------------- ERROR MANAGER ----------------------*/
bool	error_syntax(char *argv);
bool	error_dobble(t_stack **stack, int n);
void	free2d(char **str);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **stack, char **argv, char *error_msg, bool tab2d);
void	smaller_closest(t_stack *src_node, t_stack **target_stack);
void	bigger_closest(t_stack *src_node, t_stack **target_stack);
t_stack	*find_last(t_stack **stack);
int		ft_isdigit(char c);
long	ft_atol(char *argv);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_cheapest(t_stack **stack);
void	sort_three(t_stack	**stack);
bool	stack_sorted(t_stack *stack);
int		size_stack(t_stack *stack);
void	set_median(t_stack **stack);
void	set_index(t_stack **stack);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	set_stacks(t_stack **stack_a, t_stack **stack_b, char which_stack);
void	set_push_cost(t_stack *src_node, t_stack **target_stack, int index_last_node);
void	set_cheapest(t_stack **stack);
void	ft_putstr(char *str);
void	move(t_stack **stack_a, t_stack **stack_b, t_stack *node_src, bool above_median);
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	min_on_top(t_stack **stack_a);
#endif
