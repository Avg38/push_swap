/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:18:27 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/17 10:53:12 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_both(t_stack **a, t_stack **b, t_stack *src, bool above_median)
{
	if (above_median == true)
	{
		while (src->index != 0 && src->target->index != 0)
		{
			rr(a, b, false);
			set_index_median(*a);
			set_index_median(*b);
		}
	}
	else if (above_median == false)
	{
		while (src->index != 0 && src->target->index != 0)
		{
			rrr(a, b, false);
			set_index_median(*a);
			set_index_median(*b);
		}
	}
}

void	move_one(t_stack **stack, t_stack *src, char witch_stack)
{
	if (src->above_median == true)
	{
		while (src->index != 0)
		{
			if (witch_stack == 'a')
				ra(stack, false);
			else
				rb(stack, false);
			set_index_median(*stack);
		}
	}
	else if (src->above_median == false)
	{
		while (src->index != 0)
		{
			if (witch_stack == 'a')
				rra(stack, false);
			else
				rrb(stack, false);
			set_index_median(*stack);
		}
	}
}

void	move(t_stack **src, t_stack **dst, char direction)
{
	t_stack	*cheapest;
	t_stack	*target;

	if (!src)
		return ;
	cheapest = find_cheapest(src);
	target = cheapest->target;
	if ((cheapest->above_median == true && cheapest->above_median == true)
		|| (target->above_median == false && cheapest->above_median == false))
		move_both(src, dst, cheapest, cheapest->above_median);
	move_one(src, cheapest, direction);
	move_one(dst, target, direction);
	if (direction == 'a')
		pa(src, dst, false);
	if (direction == 'b')
		pb(src, dst, false);
}

// void	move_a_to_b(t_stack **a, t_stack **b)
// {
// 	t_stack	*cheapest;
// 	t_stack	*target;

// 	if (!a)
// 		return ;
// 	cheapest = find_cheapest(a);
// 	target = cheapest->target;
// 	if ((cheapest->above_median == true && cheapest->above_median == true)
// 		|| (target->above_median == false && cheapest->above_median == false))
// 		move_both(a, b, cheapest, cheapest->above_median);
// 	move_one(a, cheapest, 'a');
// 	move_one(b, target, 'b');
// 	pb(a, b, false);
// }

// void	move_b_to_a(t_stack **a, t_stack **b)
// {
// 	t_stack	*target;
// 	t_stack	*cheapest;

// 	if (!b)
// 		return ;
// 	cheapest = find_cheapest(b);
// 	target = cheapest->target;
// 	if ((cheapest->above_median == true && cheapest->above_median == true)
// 		|| (target->above_median == false && cheapest->above_median == false))
// 		move_both(a, b, cheapest, cheapest->above_median);
// 	move_one(a, target, 'a');
// 	move_one(b, cheapest, 'b');
// 	pa(a, b, false);
// }
