/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:59:02 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/29 11:04:44 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	error_syntax(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (true);
		i++;
	}
	return (false);
}

bool	error_dobble(t_stack **stack, int n)
{
	t_stack	*current;

	if (!stack)
		return (false);
	current = *stack;
	while (current)
	{
		if (current->nb == n)
			return (true);
		current = current->next;
	}
	return (false);
}

void	free2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!(*stack))
		return ;
	current = *stack;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack **stack, char **argv, bool tab2d)
{
	if (tab2d)
		free2d(argv);
	free_stack(stack);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
