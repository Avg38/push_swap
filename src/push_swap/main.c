/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:48:27 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/17 14:03:31 by avialle-         ###   ########.fr       */
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
			free_errors(&head, av, "Syntax error.", tab2d);
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_errors(&head, av, "Not bitween INT_MIN and INT_MAX.", tab2d);
		if (error_dobble(&head, n))
			free_errors(&head, av, "A value is in double.", tab2d);
		if (!add_node(&head, (int)n))
			free_errors(&head, av, "Add node is not working.", tab2d);
		i++;
	}
	if (tab2d)
		free2d(av);
	*stack = head;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		check_init_a(&a, ft_split(argv[1], ' '), true);
	else
		check_init_a(&a, argv + 1, false);
	if (!stack_sorted(a))
	{
		if (size_stack(a) == 2)
			sa(&a, false);
		else if (size_stack(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}

// void	display_stack(t_stack *stack)
// {
// 	t_stack *cur;

// 	cur = stack;
// 	while (cur)
// 	{
// 		ft_printf("nb = %d\n", cur->nb);
// 		if (cur->target)
// 			ft_printf("target = %d\n", cur->target->nb);
// 		cur = cur->next;
// 	}
// }
