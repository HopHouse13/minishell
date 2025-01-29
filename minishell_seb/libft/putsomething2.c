/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsomething2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:09:27 by swendum           #+#    #+#             */
/*   Updated: 2024/11/09 00:16:54 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putpointerfd(unsigned long ptr, size_t i, int fd)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (!ptr)
		return (write(fd, "(nil)", 5));
	if (!i)
	{
		write(fd, "0x", 2);
		i += 2;
	}
	if (ptr >= 16)
		i = (ft_putpointerfd(ptr / 16, i, fd));
	ft_putcharfd(hex[(ptr % 16)], fd);
	return (++i);
}
