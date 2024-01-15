/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:03:14 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/15 10:06:38 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

char	*extract_line(char *str, int *i)
{
	int		j;
	char	*word;

	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		(*i)++;
	j = *i;
	while (str[*i] && (str[*i] != ' ' && str[*i] != '\t'))
		(*i)++;
	if (*i > j)
	{
		word = (char *)malloc(sizeof(char) * ((*i - j) + 1));
		if (!word)
			return (NULL);
		ft_strncpy(word, &str[j], *i - j);
	}
	return (word);
}

char	**ft_split(char *str)
{
	int		i;
	int		k;
	char	**split;

	split = malloc((count_words(str) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		split[k] = extract_line(str, &i);
		if (!split[k])
			return (free2d(split), NULL);
		k++;
	}
	split[k] = NULL;
	return (split);
}
