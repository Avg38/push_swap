/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:53:08 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/11 14:34:41 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	smaller_closest(t_stack *src_node, t_stack **target_stack)
{
	int	nbr;

	if (!src_node || !target_stack)
		return (NULL);
	nbr = INT_MIN;
	while (*target_stack != NULL)
	{
		if ((*target_stack)->nb < src_node->nb && (*target_stack)->nb > nbr)
		{
			nbr = (*target_stack)->nb;
			src_node->target = *target_stack;
		}
		*target_stack = (*target_stack)->next;
	}
	if (nbr == INT_MIN)
		src_node->target = find_max(*target_stack);
}
void	bigger_closest(t_stack *src_node, t_stack **target_stack)
{
	int	nbr;

	if (!src_node || !target_stack)
		return (NULL);
	nbr = INT_MAX;
	while (*target_stack != NULL)
	{
		if ((*target_stack)->nb > src_node->nb && (*target_stack)->nb < nbr)
		{
			nbr = (*target_stack)->nb;
			src_node->target = *target_stack;
		}
		*target_stack = (*target_stack)->next;
	}
	if (nbr == INT_MAX)
		src_node->target = find_min(*target_stack);
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
		j = lst_last(target_stack)->index - src_node->index;
	if (src_node->above_median != src_node->target->above_median)
		src_node->push_cost = i + j;
	else if (i >= j && src_node->above_median == src_node->target->above_median)
		src_node->push_cost = i;
	else
		src_node->push_cost = j;
}
