/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:54:18 by swendum           #+#    #+#             */
/*   Updated: 2024/08/06 00:29:16 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		l1;
	size_t		i;
	char		*new;

	i = 0;
	l1 = ft_strlen(s1);
	new = malloc((l1 + ft_strlen(s2) + 1) * sizeof (char));
	if (!new)
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[i - l1])
	{
		new[i] = s2[i - l1];
		i++;
	}
	new[i] = 0;
	return (new);
}
