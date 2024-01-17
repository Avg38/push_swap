/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:21:37 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/17 14:45:54 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	exit_programm(t_stack **a, t_stack **b, char *verif)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (ft_strcmp(verif, "OK") == 0)
	{
		ft_printf("OK\n");
		exit(EXIT_SUCCESS);
	}
	ft_printf("KO\n");
	exit(EXIT_FAILURE);
}

void	commands(t_stack **a, t_stack **b, char *command)
{
	if (ft_strcmp(command, "pa") == 0)
		pa(b, a, true);
	if (ft_strcmp(command, "pb") == 0)
		pb(a, b, true);
	if (ft_strcmp(command, "sa") == 0)
		sa(a, true);
	if (ft_strcmp(command, "sb") == 0)
		sb(b, true);
	if (ft_strcmp(command, "ss") == 0)
		ss(a, b, true);
	if (ft_strcmp(command, "ra") == 0)
		ra(a, true);
	if (ft_strcmp(command, "rb") == 0)
		rb(b, true);
	if (ft_strcmp(command, "rr") == 0)
		rr(a, b, true);
	if (ft_strcmp(command, "rra") == 0)
		rra(a, true);
	if (ft_strcmp(command, "rrb") == 0)
		rrb(b, true);
	if (ft_strcmp(command, "rrr") == 0)
		rrr(a, b, true);
}
void	do_commands(t_stack **a, t_stack **b)
{
	int		i;
	char	*line;
	char	*tmp;
	char	**split;

	if (!a || !b)
		return ;
	tmp = get_next_line(1);
	while (tmp)
	{
		line = ft_strjoin(line, tmp);
		tmp = get_next_line(1);
	}
	i = 0;
	split = ft_split(line, '\n');
	while (split[i])
		commands(a, b, split[i++]);
	free2d(split);
	free(tmp);
	free(line);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		check_init_a(&a, ft_split(av[1], ' '), true);
	else
		check_init_a(&a, av + 1, false);
	if (!stack_sorted(a))
		do_commands(a, b);
	if (stack_sorted(a))
		exit_programm(a, b, "OK");
	exit_programm(a, b, "KO");
	return (0);
}
