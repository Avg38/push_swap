/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:14:28 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/23 13:19:53 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_node(t_stack **stack)
{
	t_stack	*first;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	if ((*stack)->next)
	{
		first->next = (*stack)->next;
		(*stack)->next = first;
	}
	else
	{
		first->next = NULL;
		(*stack)->next = first;
	}
}

void	sa(t_stack **a, bool checker)
{
	swap_node(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool checker)
{
	swap_node(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool checker)
{
	swap_node(a);
	swap_node(b);
	if (!checker)
		write(1, "ss\n", 3);
}
