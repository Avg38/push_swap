/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:08:08 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/05 11:16:20 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = lst_last(*stack);
	if (last == NULL)
		return ;
	last->next = first;
	while (last->next != first)
		last = last->next;
	last->next = NULL;
}

void	rra(t_stack **stack_a, bool checker)
{
	reverse_rotate(stack_a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, bool checker)
{
	reverse_rotate(stack_b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool checker)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (!checker)
		write(1, "rrr\n", 4);
}