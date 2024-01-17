/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:50:05 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/17 10:59:46 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*find_last(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!tmp)
		return (0);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*node_min;
	int		min;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack != NULL)
	{
		if (stack->nb < min)
		{
			min = stack->nb;
			node_min = stack;
		}
		stack = stack->next;
	}
	return (node_min);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*node_max;
	int		max;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack != NULL)
	{
		if (stack->nb > max)
		{
			max = stack->nb;
			node_max = stack;
		}
		stack = stack->next;
	}
	return (node_max);
}

t_stack	*find_cheapest(t_stack **stack)
{
	if (!stack || !(*stack))
		return (NULL);
	while (*stack != NULL)
	{
		if ((*stack)->cheapest == true)
			return (*stack);
		*stack = (*stack)->next;
	}
	return (NULL);
}
