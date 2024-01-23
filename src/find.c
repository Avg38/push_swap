/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:50:05 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/23 13:13:30 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

t_stack	*find_max_or_min(t_stack *stack, bool max)
{
	t_stack	*extrem_node;

	if (!stack)
		return (NULL);
	extrem_node = stack;
	while (stack)
	{
		if ((max == true && stack->nb > extrem_node->nb)
			|| (max == false && stack->nb < extrem_node->nb))
			extrem_node = stack;
		stack = stack->next;
	}
	return (extrem_node);
}

t_stack	*find_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
