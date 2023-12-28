/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:59:02 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/28 17:34:36 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error(void)
{
	write(1, "Error\n,", 6);
}

int	right_char(char c)
{
	if (ft_isnum(c) == 0 && c != 32
		&& c != '-' && c != '+')
		return (0);
	return (1);
}

int	verif(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (right_char(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
