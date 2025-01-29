/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:11:44 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:21:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// concatener src sur dest avec securite de pas depasser destsize avec carac.fin
// possiblite que src soit tronquee
// !!!si destsize est inferieur ou egale a dest > renvoie taille de destsize+src
// "+ 1" pour s assurer d'avoir la place pour le carac. de fin de chaine

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	len_src;	
	size_t	len_dest;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (destsize <= len_dest)
		return (destsize + len_src);
	i = 0;
	while (src[i] && (len_dest + i + 1) < destsize)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	if (len_dest + i < destsize)
		dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
