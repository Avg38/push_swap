/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:48:27 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/23 09:42:01 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	free_stack(&b);
	return (0);
}

void	display_stack(t_stack *stack)
{
	t_stack	*cur;

	cur = stack;
	while (cur)
	{
		ft_printf("nb = %d\n cheapest = %d", cur->nb, cur->cheapest);
		if (cur->target)
			ft_printf("target = %d\n", cur->target->nb);
		cur = cur->next;
	}
}
