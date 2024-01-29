/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:03:14 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/29 15:48:00 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = 0;
	return (s1);
}

static int	count_words(char *str, char sep)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
			wc++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (wc);
}

static char	*extract_line(char *str, int *i, char sep)
{
	int		j;
	char	*word;

	word = NULL;
	while (str[*i] && str[*i] == sep)
		(*i)++;
	j = *i;
	while (str[*i] && str[*i] != sep)
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

char	**ft_split(char *str, char sep)
{
	int		i;
	int		k;
	char	**split;

	split = malloc((count_words(str, sep) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		split[k] = extract_line(str, &i, sep);
		if (!split[k])
			return (free2d(split), NULL);
		k++;
	}
	split[k] = NULL;
	return (split);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[0] = '\0';
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}
