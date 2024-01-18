/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:53:08 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/18 13:45:56 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_index_median(t_stack *stack)
{
	int	median;
	int	i;

	if (!stack)
		return ;
	median = size_stack(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target(t_stack *src, t_stack *target, char witch_stack, bool max)
{
	int		nbr;
	t_stack	*cur;

	if (!src || !target)
		return ;
	while (src != NULL)
	{
		cur = target;
		nbr = INT_MIN;
		if (!max)
			nbr = INT_MAX;
		while (cur != NULL)
		{
			if ((cur->nb < src->nb && cur->nb > nbr && witch_stack == 'a')
				|| (cur->nb > src->nb && cur->nb < nbr && witch_stack == 'b'))
			{
				nbr = cur->nb;
				src->target = cur;
			}
			cur = cur->next;
		}
		if (nbr == INT_MIN || nbr == INT_MAX)
			src->target = find_max_or_min(target, max);
		src = src->next;
	}
}

// void	smaller_closest(t_stack *a, t_stack *b)
// {
// 	int		nbr;
// 	t_stack	*cur;

// 	if (!a || !b)
// 		return ;
// 	while (a != NULL)
// 	{
// 		cur = b;
// 		nbr = INT_MIN;
// 		while (cur != NULL)
// 		{
// 			if (cur->nb < a->nb && cur->nb > nbr)
// 			{
// 				nbr = cur->nb;
// 				a->target = cur;
// 			}
// 			cur = cur->next;
// 		}
// 		if (nbr == INT_MIN)
// 			a->target = find_max(b);
// 		a = a->next;
// 	}
// }

// void	bigger_closest(t_stack *b, t_stack *a)
// {
// 	int		nbr;
// 	t_stack	*current;

// 	if (!b || !a)
// 		return ;
// 	while (b != NULL)
// 	{
// 		nbr = INT_MAX;
// 		current = a;
// 		while (current != NULL)
// 		{
// 			if (current->nb > b->nb && current->nb < nbr)
// 			{
// 				nbr = current->nb;
// 				b->target = current;
// 			}
// 			current = current->next;
// 		}
// 		if (nbr == INT_MAX)
// 			b->target = find_min(a);
// 		b = b->next;
// 	}
// }

// void	set_push_cost(t_stack *src, t_stack **target_stack, int index_last)
// {
// 	int	i;
// 	int	j;

// 	if (!src || !target_stack)
// 		return ;
// 	i = 0;
// 	j = 0;
// 	if (src->above_median == true)
// 		i = src->index;
// 	else
// 		i = index_last - src->index;
// 	if (src->target->index == true)
// 		j = src->target->index;
// 	else
// 		j = find_last(target_stack)->index - src->index;
// 	if (src->above_median != src->target->above_median)
// 		src->push_cost = i + j;
// 	else if (i >= j && src->above_median == src->target->above_median)
// 		src->push_cost = i;
// 	else
// 		src->push_cost = j;
// }

void	set_push_cost(t_stack *src, t_stack *target)
{
	int	len_src;
	int	len_target;

	len_src = size_stack(src);
	len_target = size_stack(target);

	while (src)
	{
		src->push_cost = src->index;
		if (src->above_median == false)
			src->push_cost = len_src - (src->index);
		if (src->target->above_median == true)
			src->push_cost += src->target->index;
		else
			src->push_cost += len_target - (src->target->index);
		src = src->next;
	}
}

void	set_cheapest(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;
	int		tmp_cost;

	if (!stack)
		return ;
	tmp = *stack;
	tmp_cost = INT_MAX;
	current = *stack;
	while (current)
	{
		current->cheapest = false;
		current = current->next;
	}
	current = *stack;
	while (current)
	{
		if (current->push_cost < tmp_cost)
		{
			tmp = *stack;
			tmp_cost = current->push_cost;
		}
		current = current->next;
	}
	tmp->cheapest = true;
}

// void	set_median(t_stack **stack)
// {
// 	int		i;
// 	int		size;
// 	t_stack	*current;

// 	if (!stack)
// 		return ;
// 	i = 1;
// 	current = *stack;
// 	size = size_stack(*stack);
// 	while (i < size / 2 && current != NULL)
// 	{
// 		current->above_median = true;
// 		current = current->next;
// 		i++;
// 	}
// 	while (i < size && *stack != NULL)
// 	{
// 		current->above_median = false;
// 		current = current->next;
// 		i++;
// 	}
// }
