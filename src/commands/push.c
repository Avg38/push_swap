/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:08:12 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/05 11:40:58 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_node(t_stack **dest, t_stack **src)
{
	t_stack	*node_src;

	if (!(*src))
		return ;
	node_src = *src;
	*src = (*src)->next;
	node_src->next = *dest;
	*dest = node_src;
}

void	pa(t_stack **stack_a, t_stack **stack_b, bool checker)
{
	swap_node(stack_a, stack_b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a, bool checker)
{
	swap_node(stack_b, stack_a);
	if (!checker)
		write(1, "pb\n", 3);
}
