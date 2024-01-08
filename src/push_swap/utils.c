/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:41:42 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/08 11:13:44 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*lst_last(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!tmp)
		return (0);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(char *argv)
{
	long	n;
	int		sign;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	while (argv[i] == ' ' || argv[i] == '\t')
		i++;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			sign = -1;
		i++;
	}
	while (argv[i])
		n = n * 10 + (argv[i++] - '0');
	return (n * sign);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*node_min;
	int		min;

	if (!stack)
		reutrn (NULL);
	min = INT_MAX;
	while (stack != NULL)
	{
		if (stack->nb < min)
		{
			min = stack->nb;
			node_min = stack;
		}
		stack = stack->next;
	}
	return (node_min);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*node_max;
	int		max;

	if (!stack)
		reutrn (NULL);
	max = INT_MIN;
	while (stack != NULL)
	{
		if (stack->nb > max)
		{
			max = stack->nb;
			node_max = stack;
		}
		stack = stack->next;
	}
	return (node_max);
}

void	sort_three(t_stack	**stack)
{
	t_stack	*max;

	if (!stack)
		return ;
	max = find_max(*stack);
	if (*stack == max)
		ra(stack, false);
	else if ((*stack)->next == max)
		rra(stack, false);
	if ((*stack)->nb > (*stack)->next->nb)
		sa(stack, false);
}
bool	stack_sorted(t_stack **stack)
{
	if (!stack)
		return (NULL);
	while ((*stack)->next != NULL)
	{
		if ((*stack)->nb > (*stack)->next->nb)
			return (false);
		(*stack) = (*stack)->next;
	}
	return (true);
}

int	size_stack(t_stack **stack)
{
	int	i;

	if (!stack)
		return (NULL);
	i = 0;
	while ((*stack)->next != NULL)
	{
		
	}
}
