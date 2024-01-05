/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:08:14 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/05 11:16:09 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = stack;
	stack = first->next;
	last = lst_last(stack);
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **stack_a, bool checker)
{
	rotate(stack_a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, bool checker)
{
	rotate(stack_b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, bool checker)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!checker)
		write(1, "rr\n", 3);
}
