/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:34:19 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/28 17:36:44 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

int		main(int argc, char **argv);
void	error(void);
int		verif(char *argv);


#endif
