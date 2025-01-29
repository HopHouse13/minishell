/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:32:22 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:21:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// dupliquer une une partie de la src dans une sous chaine
// si l'indice (start) est > ou = a la len de src
// -> return une chaine vide (strdup)
// si longueur de la sous chaine est > (len de src)-(l'indice de depart(start))
// -> tronquer len pour pas quelle depasse src
// s_new = ft_calloc et duplique avec while (pour pas depasser src)
// et if (pour pas depasser len)

char	*ft_substr(char const *s_src, unsigned int start, size_t len)
{
	char	*s_new;
	size_t	i;
	size_t	j;

	if (!s_src)
		return (NULL);
	if (start >= ft_strlen(s_src))
		return (ft_strdup(""));
	if (len > ft_strlen(s_src) - start)
		len = ft_strlen(s_src) - start;
	s_new = ft_calloc((len + 1), sizeof(char));
	if (!s_new)
		return (NULL);
	i = start;
	j = 0;
	while (s_src[i])
	{
		if (j < len)
			s_new[j++] = s_src[i];
		i++;
	}
	s_new[j] = '\0';
	return (s_new);
}
