/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:41:42 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/05 16:17:10 by avialle-         ###   ########.fr       */
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
