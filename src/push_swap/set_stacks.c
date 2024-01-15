/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:53:08 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/15 16:19:38 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	smaller_closest(t_stack *src_node, t_stack **target_stack)
{
	int		nbr;
	t_stack	*current;
	t_stack	*first_target_stack;

	if (!src_node || !target_stack)
		return ;
	first_target_stack = *target_stack;
	while (src_node != NULL)
	{
		current = first_target_stack;
		nbr = INT_MIN;
		while (current != NULL)
		{
			if (current->nb < src_node->nb && current->nb > nbr)
			{
				nbr = current->nb;
				src_node->target = current;
			}
			current = current->next;
		}
		if (nbr == INT_MIN)
			src_node->target = find_max(*target_stack);
		src_node = src_node->next;
	}
}

void	bigger_closest(t_stack *src_node, t_stack **target_stack)
{
	int		nbr;
	t_stack	*current;
	t_stack	*first_target_stack;

	if (!src_node || !target_stack)
		return ;
	first_target_stack = *target_stack;
	while (src_node != NULL)
	{
		nbr = INT_MAX;
		current = first_target_stack;
		while (current != NULL)
		{
			if (current->nb > src_node->nb && current->nb < nbr)
			{
				nbr = current->nb;
				src_node->target = current;
			}
			current = current->next;
		}
		if (nbr == INT_MAX)
			src_node->target = find_min(*target_stack);
		src_node = src_node->next;
	}
}

void	set_push_cost(t_stack *src_node, t_stack **target_stack, int index_last_node)
{
	int	i;
	int	j;

	if (!src_node || !target_stack)
		return ;
	i = 0;
	j = 0;
	if (src_node->above_median == true)
		i = src_node->index;
	else
		i = index_last_node - src_node->index;
	if (src_node->target->index == true)
		j = src_node->target->index;
	else
		j = find_last(target_stack)->index - src_node->index;
	if (src_node->above_median != src_node->target->above_median)
		src_node->push_cost = i + j;
	else if (i >= j && src_node->above_median == src_node->target->above_median)
		src_node->push_cost = i;
	else
		src_node->push_cost = j;
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
