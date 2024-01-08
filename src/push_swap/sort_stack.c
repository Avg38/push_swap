/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:51:29 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/08 15:55:59 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = size_stack(&stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b, false);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b, false);
	while (len_a-- > 3)
	{
		init_stacks(stack_a, stack_b, 'a');
		move_a_to_b(stack_a, stack_b);
	}
	while (stack_b != NULL)
	{
		init_stacks(stack_a, stack_b, 'b');
		move_b_to_a(stack_a, stack_b);
	}
	free_stack(stack_a);
}

void	init_stacks(t_stack **stack_a, t_stack **stack_b, char which_stack)
{
	set_index(stack_a);
	set_index(stack_b);
	set_median(stack_a);
	set_median(stack_b);
	if (which_stack == 'a')
	{
		while (*stack_a != NULL)
		{
			smaller_closest(*stack_a, stack_b);
			set_push_cost(*stack_a, stack_b);
			*stack_a = (*stack_a)->next;
		}
	}
	else if (which_stack == 'b')
	{
		while (*stack_b != NULL)
		{
			bigger_closest(*stack_b, stack_a);
			set_push_cost(stack_b, stack_a);
			*stack_b = (*stack_b)->next;
		}
	}
}
