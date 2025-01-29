/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:51:08 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:21:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// remplace n premier octets sur la chaine d'octets par le carac. (int c)
// la chaine peut etre de tous types
// -> conversion en unsigned char (chaine/carac.) pour les manipuler ensemble

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	carac_tempo;
	unsigned char	*string_tempo;
	unsigned int	i;

	carac_tempo = c;
	string_tempo = s;
	i = 0;
	while (i < n)
	{
		string_tempo [i] = carac_tempo;
		i++;
	}
	return (s);
}
