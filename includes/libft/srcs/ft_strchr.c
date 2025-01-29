/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:03:50 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:21:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// recherche la 1eme occurence dans la chaine de carac.
// boucle : tant que str existe et qu'aucune occurrence est trouvee > i++
// si occurrence trouvee > sortie de la boucle > if (securite occurrence)
// > return le  pointeur de l'occurrence (en hexadécimal)
// si pas d'occurence, return NULL
// "int c" est cast en (char) > comparaison entre les (char *) et le char c
// le return est cast en (char *) > const char en parametre et en sortie char
// cast = transtypage

char	*ft_strchr(const char *str, int c)
{
	size_t		i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}

// int	main(void)
// {
// 	const char string[] = "Hello, World!";
// 	int character_to_find = 'W';

// 	printf("[%p]\n", ft_strchr(string, character_to_find));
// 	return 0;
// }