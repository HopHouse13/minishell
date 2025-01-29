/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:59:31 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:21:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// 		Dupliquer le contenu de s1 sans les carac. contenu dans set
// 		ces carac. se trouvent au debut et/ou a la fin
// - Securites : s1 = 0 -> NULL; s1 = '\0' -> chaine avec '\0'
// - Boucle du debut en checkant chaque carac. de s1[start] avec "ft_setchr"
// -> '1' carac. trouve -> s1start++; '0' carac. pas trouve -> stop l'avancement
// - Boucle de la fin en checkant si end > start et en demarrant a -1 
// [indice de deplacement tjs +1 par rapport au "case memoire" de la chaine]
// - Allocation memoire (Malloc) sur new_str puis copie avec ft_strlcpy
// [Dans le malloc, le "sizeof" avec la taille du type que new_str a]
static int	ft_setchr(const char *str, int c)
{
	size_t		i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new_str;

	start = 0;
	end = (ft_strlen(s1));
	if (set == NULL)
		return (NULL);
	if (ft_strlen(s1) == '\0')
		return (ft_strdup(""));
	while (s1[start] && ft_setchr(set, s1[start]))
		start++;
	while (s1[end - 1] && end > start && ft_setchr(set, s1[end - 1]))
		end--;
	new_str = malloc((sizeof * new_str) * (end - start + 1));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, &s1[start], (end - start + 1));
	return (new_str);
}
