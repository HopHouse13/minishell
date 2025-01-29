/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:28:37 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:21:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//	recherche un carac. (int) dans une chaine d'octets (s*) sur une longueur 'n'
//	Bibli. libft.h est inclut pour appeler bibli. stdlib/stdio pour size_t
//	-> conversion de la chaise et du carac. pour poivoir les comparer
//	!!! (s_tempo[i]) != (s_tempo + i)

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c_tempo;
	unsigned char	*s_tempo;
	unsigned int	i;

	c_tempo = (unsigned char )c;
	s_tempo = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (s_tempo[i] == c_tempo)
			return ((void *)(s_tempo + i));
		i++;
	}
	return (NULL);
}
