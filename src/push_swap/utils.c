/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:41:42 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/12 14:43:28 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

t_stack	*find_last(t_stack **stack)
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
		return (NULL);
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
		return (NULL);
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

t_stack	*find_cheapest(t_stack **stack)
{
	if (!stack)
		return (NULL);
	while (*stack != NULL)
	{
		if ((*stack)->cheapest == true)
			return (*stack);
		*stack = (*stack)->next;
	}
	return (NULL);
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
		return (0);
	i = 0;
	while (*stack != NULL)
	{
		i++;
		*stack = (*stack)->next;
	}
	return (i);
}

void	set_median(t_stack **stack)
{
	int	i;
	int	size;

	if (!stack)
		return ;
	i = 0;
	size = size_stack(stack);
	if (size % 2 == 0)
		i = 1;
	while (i <= size / 2 && *stack != NULL)
	{
		(*stack)->above_median = true;
		*stack = (*stack)->next;
		i++;
	}
	while (i < size && *stack != NULL)
	{
		(*stack)->above_median = false;
		*stack = (*stack)->next;
		i++;
	}
}

void	set_index(t_stack **stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (*stack != NULL)
	{
		(*stack)->index = i;
		i++;
		*stack = (*stack)->next;
	}
}