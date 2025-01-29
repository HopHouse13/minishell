/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:09:45 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:21:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdint.h>
// count = nbr de case memoire (on navigue dedans l'indice i)
// size = la taille de chaque case memoire (ex: chr , int, etc)
// Securites:
//	1] si count < 1 ou size < 1 (protection si negatif): ptr -> vers malloc (0)
//	return le pointeur ptr.
//	2] count ne doit pas depasser (la taille max du type / "unite" du type
//	ex : int_max (2147483647) / un int a 4 octets = 536870911
//	le nombre de count ne doit pas depasser 536870911 sinon NULL
// 	while (i <= (count * size))
// 	{
// 		ptr[i] = '\0';
// 		i++;
// 	}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total;
	unsigned char	*ptr;

	if (count < 1 || size < 1)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
