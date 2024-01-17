/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:51:29 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/17 10:51:48 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_stacks(t_stack **a, t_stack **b, char which_stack)
{
	set_index_median(*a);
	set_index_median(*b);
	if (which_stack == 'a')
	{
		smaller_closest(*a, b);
		set_push_cost(*a, b, find_last(a)->index);
		set_cheapest(a);
	}
	else if (which_stack == 'b')
	{
		bigger_closest(*b, a);
		set_push_cost(*b, a, find_last(b)->index);
		set_cheapest(b);
	}
}

bool	stack_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (true);
	current = stack;
	while (current->next != NULL)
	{
		if (current->nb > current->next->nb)
			return (false);
		current = current->next;
	}
	return (true);
}

void	sort_three(t_stack	**stack)
{
	t_stack	*max;

	if (!stack || !(*stack))
		return ;
	max = find_max(*stack);
	if (*stack == max)
		ra(stack, false);
	else if ((*stack)->next == max)
		rra(stack, false);
	if ((*stack)->nb > (*stack)->next->nb)
		sa(stack, false);
}

void	min_on_top(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	if (!min)
		return ;
	while (true)
	{
		if ((*a)->nb == min->nb)
			break ;
		if (min->above_median == true)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = size_stack(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		set_stacks(a, b, 'a');
		move(a, b, 'b');
	}
	sort_three(a);
	while (*b)
	{
		set_stacks(a, b, 'b');
		move(b, a, 'a');
	}
	set_index_median(*a);
	min_on_top(a);
}
