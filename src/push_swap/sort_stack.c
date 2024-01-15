/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:51:29 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/15 14:21:34 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = size_stack(*stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b, false);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b, false);
	while (len_a-- > 3 && stack_sorted(*stack_a))
	{
		set_stacks(stack_a, stack_b, 'a');
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		set_stacks(stack_a, stack_b, 'b');
		move_b_to_a(stack_a, stack_b);
	}
	set_index(stack_a);
	min_on_top(stack_a);
}

void	set_stacks(t_stack **stack_a, t_stack **stack_b, char which_stack)
{
	set_index(stack_a);
	set_index(stack_b);
	set_median(stack_a);
	set_median(stack_b);
	if (which_stack == 'a')
	{
		smaller_closest(*stack_a, stack_b);
		set_push_cost(*stack_a, stack_b, find_last(stack_a)->index);
		set_cheapest(stack_a);
	}
	else if (which_stack == 'b')
	{
		bigger_closest(*stack_b, stack_a);
		set_push_cost(*stack_b, stack_a, find_last(stack_b)->index);
		set_cheapest(stack_b);
	}
}
