/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:53:08 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/17 10:57:36 by avialle-         ###   ########.fr       */
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

void	smaller_closest(t_stack *src, t_stack **target_stack)
{
	int		nbr;
	t_stack	*current;
	t_stack	*first_target_stack;

	if (!src || !target_stack)
		return ;
	first_target_stack = *target_stack;
	while (src != NULL)
	{
		current = first_target_stack;
		nbr = INT_MIN;
		while (current != NULL)
		{
			if (current->nb < src->nb && current->nb > nbr)
			{
				nbr = current->nb;
				src->target = current;
			}
			current = current->next;
		}
		if (nbr == INT_MIN)
			src->target = find_max(*target_stack);
		src = src->next;
	}
}

void	bigger_closest(t_stack *src, t_stack **target_stack)
{
	int		nbr;
	t_stack	*current;
	t_stack	*first_target_stack;

	if (!src || !target_stack)
		return ;
	first_target_stack = *target_stack;
	while (src != NULL)
	{
		nbr = INT_MAX;
		current = first_target_stack;
		while (current != NULL)
		{
			if (current->nb > src->nb && current->nb < nbr)
			{
				nbr = current->nb;
				src->target = current;
			}
			current = current->next;
		}
		if (nbr == INT_MAX)
			src->target = find_min(*target_stack);
		src = src->next;
	}
}

void	set_push_cost(t_stack *src, t_stack **target_stack, int index_last)
{
	int	i;
	int	j;

	if (!src || !target_stack)
		return ;
	i = 0;
	j = 0;
	if (src->above_median == true)
		i = src->index;
	else
		i = index_last - src->index;
	if (src->target->index == true)
		j = src->target->index;
	else
		j = find_last(target_stack)->index - src->index;
	if (src->above_median != src->target->above_median)
		src->push_cost = i + j;
	else if (i >= j && src->above_median == src->target->above_median)
		src->push_cost = i;
	else
		src->push_cost = j;
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
	while (current != NULL)
	{
		current->cheapest = false;
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
