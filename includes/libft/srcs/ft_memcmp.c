/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:04:38 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:21:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//compare 2 chaines d'octets de 'n'(nbr d'octets a comparer)
//2 pointeurs temporaires (s1/s2_tempo) sont declarer et initialiser
//aux memes emplacements que s1/s2
//comparaision de chaines sans les manipuler directement 
//bouble (si difference entre le [i] eme octets des 2 chaines)
// -> return la dif. des 2 octets compares

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_tempo;
	unsigned char	*s2_tempo;
	size_t			i;

	s1_tempo = (unsigned char *)s1;
	s2_tempo = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1_tempo[i] != s2_tempo[i])
			return (s1_tempo[i] - s2_tempo[i]);
		i++;
	}
	return (0);
}
