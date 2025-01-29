/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:02:05 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:21:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// recherche la derniere occurence dans la chaine de carac.
// definir la longueur str et le definir sur i > boucle en commencant a la fin
// si pas d'occurrence > i--
// si occ. -> return le pointeur sinon -> NULL
// Int pour l'index > int peut etre negatif (contrairement size_t)
// a i = 0, si pas d'occ > on rentre dans la boucle et decrementation > i = -1
// imposible avec size_t

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0 && (str[i] != (char)c))
		i--;
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}

// int	main(void)
// {
// 	const char string[] = "Hello world !";
// 	int character_to_find = 'w';

// 	printf("[%p]\n", ft_strrchr(string, character_to_find));
// 	return 0;
// }