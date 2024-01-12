/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:40:32 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/12 15:45:08 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	add_node(t_stack **stack, int n)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return (false);
	new_node = (t_stack *)malloc(1 * sizeof(t_stack));
	if (!new_node)
		return (false);
	new_node->nb = n;
	new_node->next = NULL;
	if (!(*stack))
		*stack = new_node;
	else
	{
		last_node = find_last(stack);
		last_node->next = new_node;
	}
	return (true);
}

void	check_init_stack_a(t_stack **stack, char **argv, bool tab2d)
{
	int	n;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(stack, argv, "Syntax error.", tab2d);
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_errors(stack, argv, "Not bitween INT_MIN and INT_MAX.", tab2d);
		if (error_dobble(stack, n))
			free_errors(stack, argv, "A value is in double.", tab2d);
		if (!add_node(stack, n))
			free_errors(stack, argv, "Add node is not working.", tab2d);
		i++;
	}
	if (tab2d)
		free2d(argv);
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = 0;
	return (s1);
}

int	count_words(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
	}
	return (wc);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	int		wc;
	char	**split;

	wc = count_words(str);
	split = malloc((wc + 1) * sizeof(char *));
	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
		if (i > j)
		{
			split[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(split[k++], &str[j], i - j);
		}
	}
	split[k] = NULL;
	return (split);
}
