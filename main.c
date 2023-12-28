/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:48:27 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/28 16:45:04 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		if (verif(argv[i] == 0))
			return (error(), NULL)
	}
	verif(argv);
	put_in_table(argv);
	return (0);
}
