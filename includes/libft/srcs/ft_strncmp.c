/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:18:09 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:21:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// compare str1 et str2 pour n carac.
// boucle d'incrementation tant que les carac. sont egaux
// si difference trouvee avant n -> return la difference
// si pas de diff. et fin de str1 ou str2 ou fin n -> return 0

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	if (i < n)
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}

// #include "../includes/libft.h"

// int	main(void)
// {
// 	char str1[] = "hello, copain!";
// 	char str2[] = "hello, copain!";
// 	size_t	i = 3;
// 	printf("[%d]\n", ft_strncmp(str1, str2, i));
// 	return (0);
// }