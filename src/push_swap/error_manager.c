/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:59:02 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/05 14:44:26 by avialle-         ###   ########.fr       */
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
		if (!ft_isdigit(argv[i]))
			return (true);
	return (false);
}

bool	error_dobble(t_stack *stack, int n)
{
	if (!stack)
		return (false);
	while (stack)
	{
		if (stack->nb == n)
			return (true);
		stack = stack->next;
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
	while (tmp->next != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	(*stack) = NULL;
}

void	free_errors(t_stack **stack, char **argv, char *error_msg, bool tab2d)
{
	if (tab2d)
		free2d(argv);
	free_stack(stack);
	ft_putstr(error_msg);
	exit(EXIT_FAILURE);
}
