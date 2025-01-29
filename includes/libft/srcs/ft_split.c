/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:34:53 by pbret             #+#    #+#             */
/*   Updated: 2025/01/22 16:48:29 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_nbr_words(char const *s, char c)
{
	long int		i;
	size_t			nbr;
	int				same_carac;

	i = 0;
	nbr = 0;
	same_carac = 0;
	while (s[i])
	{
		if (s[i] != c && same_carac == 0)
		{
			nbr++;
			same_carac = 1;
		}	
		else if (s[i] == c)
			same_carac = 0;
		i++;
	}
	return (nbr);
}

static char	*ft_alloue_and_copy_word(char const *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc((end - start + 1), sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	return (word);
}

static void	*ft_free_double_tab_tab(char **tab_tab, size_t w)
{
	size_t	i;

	i = 0;
	while (i < w)
	{
		free(tab_tab[i]);
		i++;
	}
	free(tab_tab);
	return (NULL);
}

static void	ft_init(size_t *i, size_t *w, int *first_carac)
{
	*i = 0;
	*w = 0;
	*first_carac = -1;
}

char	**ft_split(char const *s, char c)
{
	char		**tab_tab;
	size_t		i;
	int			first_carac;
	size_t		w;

	tab_tab = ft_calloc(ft_nbr_words(s, c) + 1, sizeof(char *));
	if (!tab_tab)
		return (NULL);
	ft_init(&i, &w, &first_carac);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && first_carac < 0)
			first_carac = i;
		else if ((s[i] == c || i == ft_strlen(s)) && first_carac >= 0)
		{
			tab_tab[w] = ft_alloue_and_copy_word(s, first_carac, i);
			if (!tab_tab[w])
				return (ft_free_double_tab_tab(tab_tab, w));
			first_carac = -1;
			w++;
		}
		i++;
	}
	return (tab_tab);
}

// int 	main(void)
// {
// 	char	*str = "  Bonjour  je m'appelle   Pierre.  ";
// 	char	c = ' ';
// 	int	i = 0;
// 	while(i < 4)
// 	{
// 		printf("Value: [%s]\n", ft_split(str, c)[i]);
// 		i++;
// 	}
// 	return(0);
// }