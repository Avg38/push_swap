/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:21:37 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/18 11:13:19 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	exit_programm(t_stack **a, t_stack **b)
{
	if (stack_sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	free_stack(b);
}

int	do_commands(t_stack **a, t_stack **b, char *command)
{
	if (ft_strcmp(command, "pa\n") == 0)
		pa(b, a, true);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(a, b, true);
	else if (ft_strcmp(command, "sa\n") == 0)
		sa(a, true);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(b, true);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(a, b, true);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(a, true);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(b, true);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(a, b, true);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(a, true);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(b, true);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(a, b, true);
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		check_init_a(&a, ft_split(av[1], ' '), true);
	else
		check_init_a(&a, av + 1, false);
	line = get_next_line(0);
	while (line)
	{
		if (do_commands(&a, &b, line) == 0)
		{
			free_stack(&b);
			free_errors(&a, av, false);
		}
		line = get_next_line(0);
	}
	exit_programm(&a, &b);
	return (0);
}
