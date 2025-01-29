/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:53:57 by swendum           #+#    #+#             */
/*   Updated: 2024/06/02 15:53:57 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	countwords(const char *s, char c)
{
	size_t			i;
	size_t			words;
	unsigned char	bool;

	bool = 1;
	i = 0;
	words = 0;
	while (s[i])
	{
		if (bool && s[i] != c)
		{
			words++;
			bool = 0;
		}
		if (s[i] == c)
			bool = 1;
		i++;
	}
	return (words);
}

unsigned char	clean(char **tab, size_t w)
{
	if (!tab[w])
	{
		while (w > 0)
			free(tab[--w]);
		free(tab);
		return (1);
	}
	return (0);
}

void	filltab(const char *s, char c, char **tab, size_t i)
{
	size_t			j;
	size_t			w;
	unsigned char	bool;

	w = 0;
	bool = 1;
	while (s[i])
	{
		j = 0;
		if (bool && s[i] != c)
		{
			while (s[i] && s[i] != c)
				tab[w][j++] = s[i++];
			tab[w++][j] = 0;
			bool = 0;
		}
		if (!s[i])
			return ;
		if (s[i] == c)
			bool = 1;
		i++;
	}
}

int	createtab(const char *s, char c, char **tab, size_t i)
{
	size_t			j;
	size_t			w;
	unsigned char	bool;

	w = 0;
	bool = 1;
	while (s[i])
	{
		j = 0;
		if (bool && s[i] != c)
		{
			while (s[i + j] && s[i + j] != c)
				j++;
			tab[w] = malloc((j + 1) * sizeof(char));
			if (clean(tab, w))
				return (0);
			bool = 0;
			w++;
		}
		if (s[i] == c)
			bool = 1;
		i++;
	}
	filltab(s, c, tab, 0);
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	size_t	words;

	if (!s)
		return (NULL);
	words = countwords(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (createtab(s, c, tab, 0) == 0)
		return (NULL);
	tab[words] = NULL;
	return (tab);
}
