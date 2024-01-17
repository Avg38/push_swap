/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:58:14 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/17 15:39:47 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	add_node(t_stack **stack, int n)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return (false);
	new_node = (t_stack *)malloc(1 * sizeof(t_stack));
	if (!new_node)
		return (false);
	new_node->nb = n;
	new_node->next = NULL;
	if (!(*stack))
		*stack = new_node;
	else
	{
		last_node = find_last(stack);
		last_node->next = new_node;
	}
	return (true);
}

void	check_init_a(t_stack **stack, char **av, bool tab2d)
{
	long	n;
	int		i;
	t_stack	*head;

	i = 0;
	head = NULL;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_errors(&head, av, tab2d);
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_errors(&head, av, tab2d);
		if (error_dobble(&head, n))
			free_errors(&head, av, tab2d);
		if (!add_node(&head, (int)n))
			free_errors(&head, av, tab2d);
		i++;
	}
	if (tab2d)
		free2d(av);
	*stack = head;
}
