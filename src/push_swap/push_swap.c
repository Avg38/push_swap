/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:48:27 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/08 13:33:34 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 && !(argv[1][0]))
		return (1);
	else if (argc == 2)
		check_init_stack_a(&a, ft_split(argv[1]), true);
	else
		check_init_stack_a(&a, argv + 1, false);
	if (!stack_sorted(a))
	{
		if (size_stack(a) == 2)
			sa(&a, true);
		if (size_stack(a) == 3)
			sort_three(a);
		else
			sort_stack(a, b);
	}
	free_stack(&a);
	return (0);
}
