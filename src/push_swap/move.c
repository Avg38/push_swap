/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:18:27 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/15 16:33:47 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_both(t_stack **stack_a, t_stack **stack_b, t_stack *node_src, bool above_median)
{
	if (above_median == true)
	{
		while (node_src->index != 0 && node_src->target->index != 0)
		{
			rr(stack_a, stack_b, false);
			set_index(stack_a);
			set_index(stack_b);
		}
	}
	else if (above_median == false)
	{
		while (node_src->index != 0 && node_src->target->index != 0)
		{
			rrr(stack_a, stack_b, false);
			set_index(stack_a);
			set_index(stack_b);
		}
	}
}

void	move_one(t_stack **stack, t_stack *node_src, char witch_stack)
{
	if (node_src->above_median == true)
	{
		while (node_src->index != 0)
		{
			if (witch_stack == 'a')
				ra(stack, false);
			else
				rb(stack, false);
			set_index(stack);
		}
	}
	else if (node_src->above_median == false)
	{
		while (node_src->index != 0)
		{
			if (witch_stack == 'a')
				rra(stack, false);
			else
				rrb(stack, false);
			set_index(stack);
		}
	}
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	if (!stack_a)
		return ;
	a = find_cheapest(stack_a);
	b = a->target;
	if (a->above_median == true && b->above_median == true)
		move_both(stack_a, stack_b, a, true);
	else if (a->above_median == false && b->above_median == false)
		move_both(stack_a, stack_b, a, false);
	move_one(stack_a, a, 'a');
	move_one(stack_b, b, 'b');
	pb(stack_a, stack_b, false);
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	if (!stack_b)
		return ;
	b = find_cheapest(stack_b);
	a = b->target;
	if (a->above_median == true && b->above_median == true)
		move_both(stack_a, stack_b, b, true);
	else if (a->above_median == false && b->above_median == false)
		move_both(stack_a, stack_b, b, false);
	move_one(stack_a, a, 'a');
	move_one(stack_b, b, 'b');
	pa(stack_a, stack_b, false);
}
