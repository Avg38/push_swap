/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:53:08 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/23 13:13:55 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	while (src)
	{
		cur = target;
		nbr = INT_MIN;
		if (!max)
			nbr = INT_MAX;
		while (cur)
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

void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	int		tmp_cost;

	if (!stack)
		return ;
	tmp_cost = INT_MAX;
	while (stack)
	{
		stack->cheapest = false;
		if (stack->push_cost < tmp_cost)
		{
			cheapest_node = stack;
			tmp_cost = stack->push_cost;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
