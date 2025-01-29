/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:52:52 by swendum           #+#    #+#             */
/*   Updated: 2024/06/02 15:52:52 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_size(long n)
{
	size_t	s;

	s = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		s++;
	}
	while (n)
	{
		n = n / 10;
		s++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	s;
	long	big;

	s = get_size((long) n);
	big = (long) n;
	str = malloc((s + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		big = big * -1;
	}
	if (n == 0)
		str[0] = '0';
	str[s] = 0;
	while (s && big)
	{
		str[--s] = (big % 10) + '0';
		big = big / 10;
	}
	return (str);
}
