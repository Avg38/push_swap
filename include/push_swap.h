/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:34:19 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/08 09:48:17 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*------------------------ INCLUDES ------------------------*/
# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

/*------------------------ STRUCTURE ------------------------*/
typedef struct s_stack
{
	int				nb;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
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
void	init_stack_a(t_stack **stack, char **argv, bool tab2d);
char	*ft_strncpy(char *s1, char *s2, int n);
int		count_words(char *str);
char	**ft_split(char *str);
bool	error_syntax(char *argv);
bool	error_dobble(t_stack *stack, int n);
void	free2d(char **str);
void	free_stack(t_stack **stack);
void	init_stack_a(t_stack **stack, char **argv, bool tab2d);

#endif
