/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:07:47 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:21:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//	cherche une chaine(*little) dans une autre chaine(*big) sur len carac.
//	calcule de la longueur a chercher
//	si la longueur est NULL -> renvoie 1er pointeur de big
//	1eme boucle pour gerer l'avancement de big -> tant que big existe
//	et que l'index < longueur a checker (len)
//	2eme boucle start -> occurrence trouvee et qu'on depasse pas (len)
//	incrementation (++i)
//	si i = longueur de (*little) -> la totalite de (*little) a ete trouve
//	return du 1er pointeur big ou la 1eme occurrence a ete trouve 

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_l;

	len_l = ft_strlen(little);
	if (len_l == 0)
		return ((char *)big);
	j = 0;
	while (big[j] && j < len)
	{
		i = 0;
		while ((little[i] == big[j + i]) && ((j + i) < len))
		{
			if (i == (len_l - 1))
				return ((char *)big + j);
			i++;
		}
		j++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str1[] = "Bonjour ola bomDia hello";
// 	char	str2[] = "bomDia";
// 	size_t	len = 18;

// 	printf("[%c]\n", *ft_strnstr(str1, str2, len));
// 	return(0);
// }