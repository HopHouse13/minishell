/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:51:44 by swendum           #+#    #+#             */
/*   Updated: 2024/06/02 15:51:44 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int		i;
	int		c;
	long	r;
	long	s;

	s = 1;
	i = 0;
	r = 0;
	c = -1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9' && c++ > -2)
		r = r * 10 + (str[i++] - 48);
	if (c > 10)
		return (9876543210);
	return (r * s);
}
