/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:48:27 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/12 14:50:19 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || !(argv[1][0]))
		return (1);
	else if (argc == 2)
		check_init_stack_a(&stack_a, ft_split(argv[1]), true);
	else
		printf("1");
		// check_init_stack_a(&stack_a, argv + 1, false);
	// if (!stack_sorted(&stack_a))
	// {
	// 	if (size_stack(&stack_a) == 2)
	// 		sa(&stack_a, true);
	// 	if (size_stack(&stack_a) == 3)
	// 		sort_three(&stack_a);
	// 	else
	// 		sort_stack(&stack_a, &stack_b);
	// }
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}