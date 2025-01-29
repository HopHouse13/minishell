/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:03:45 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:21:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Convertion d'int en string dans une chaine de carac. (char*)
// Fontion size : compte le nbr de zones de memoires a allouer
// n <= 0 -> +1 pour la place du '-' au debut
// Si n != 0 -> +1 et n/10 pour decaler la virgule jusqu'a 0
// avec la taille de notre futur str -> allocation de zones de memoire +1->'\0'
// Si n < 0 -> rajout du '-' position [0] & on passe nbr en positif (*-1)
// Boucle tant que nbr < 0 
// -> i-- au debut (position toujours -1 a la len)
// -> commence de la fin, isolation du dernier(%10) +convetion en carac. ASCII
// -> decalage de la virgule
// Une fois a nbr > 0, tout est converti return str (premier pointeur)

static int	size(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	long int		i;

	i = size(n);
	nbr = n;
	str = ft_calloc(((i) + 1), (sizeof * str));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		i--;
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
