/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:08:12 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/23 13:19:44 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_node(t_stack **dest, t_stack **src)
{
	t_stack	*node_src;

	if (!(*src))
		return ;
	node_src = *src;
	*src = node_src->next;
	node_src->next = *dest;
	*dest = node_src;
}

void	pa(t_stack **b, t_stack **a, bool checker)
{
	push_node(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, bool checker)
{
	push_node(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
