/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:18:27 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/18 16:47:18 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_both(t_stack **a, t_stack **b, t_stack *cheap, bool above_median)
{
	if (above_median == true)
		while (*a != cheap && *b != cheap->target)
			rr(a, b, false);
	else if (above_median == false)
		while (*a != cheap && *b != cheap->target)
			rrr(a, b, false);
	set_index_median(*a);
	set_index_median(*b);
}

void	move_one(t_stack **stack, t_stack *cheap, char which_stack)
{
	while (*stack != cheap)
	{
		if (which_stack == 'a')
		{
			if (cheap->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (which_stack == 'b')
		{
			if (cheap->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
	set_index_median(*stack);
}

void	move(t_stack **src, t_stack **dst, char direction)
{
	t_stack	*cheapest;

	if (!src)
		return ;
	cheapest = find_cheapest(*src);
	if ((cheapest->above_median && cheapest->target->above_median)
		|| (!(cheapest->above_median) && !(cheapest->target->above_median)))
		move_both(src, dst, cheapest, cheapest->above_median);
	move_one(src, cheapest, direction);
	if (direction == 'a')
		move_one(dst, cheapest->target, 'b');
	else if (direction == 'b')
		move_one(dst, cheapest->target, 'a');
	if (direction == 'a')
		pa(src, dst, false);
	if (direction == 'b')
		pb(src, dst, false);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	if (!a)
		return ;
	cheapest = find_cheapest(*a);
	if ((cheapest->above_median && cheapest->target->above_median)
		|| (!(cheapest->above_median) && !(cheapest->target->above_median)))
		move_both(a, b, cheapest, cheapest->above_median);
	move_one(a, cheapest, 'a');
	move_one(b, cheapest->target, 'b');
	pb(a, b, false);
}

void	move_b_to_a(t_stack **b, t_stack **a)
{
	t_stack	*cheapest;

	if (!b)
		return ;
	cheapest = find_cheapest(*b);
	if ((cheapest->above_median && cheapest->target->above_median)
		|| (!(cheapest->above_median) && !(cheapest->target->above_median)))
		move_both(b, a, cheapest, cheapest->above_median);
	move_one(b, cheapest, 'b');
	move_one(a, cheapest->target, 'a');
	pa(b, a, false);
}
