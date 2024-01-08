/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:53:08 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/08 16:38:18 by avialle-         ###   ########.fr       */
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

void	set_push_cost(t_stack *src_node, t_stack **target_stack)
{
	
}
