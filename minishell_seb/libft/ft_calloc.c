/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:52:09 by swendum           #+#    #+#             */
/*   Updated: 2024/06/02 15:52:09 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*t;
	size_t			i;

	i = 0;
	t = malloc(count * size);
	if (!t)
		return (NULL);
	while (i < count * size)
		t[i++] = 0;
	return (t);
}
