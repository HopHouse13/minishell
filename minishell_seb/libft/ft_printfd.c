/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:29:00 by swendum           #+#    #+#             */
/*   Updated: 2024/11/12 00:41:01 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	printtypefd(const char type, va_list args, size_t plen, int fd)
{
	if (type == 'c')
		plen += ft_putcharfd(va_arg(args, int), fd);
	else if (type == 's')
		plen += ft_putstrfd(va_arg(args, char *), fd);
	else if (type == 'p')
		plen += ft_putpointerfd(va_arg(args, unsigned long), 0, fd);
	else if (type == 'd' || type == 'i')
		plen += ft_putintfd(va_arg(args, int), 0, fd);
	else if (type == 'u')
		plen += ft_putuintfd(va_arg(args, unsigned int), 0, fd);
	else if (type == 'x' || type == 'X')
		plen += ft_puthexafd(va_arg(args, unsigned int), type, 0, fd);
	else
		plen += ft_putcharfd('%', fd);
	return (plen);
}

int	ft_printfd(int fd, const char *str, ...)
{
	size_t	i;
	va_list	args;
	size_t	plen;

	if (!str)
		return (-1);
	plen = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			plen = printtypefd(str[++i], args, plen, fd);
		else
			plen += ft_putcharfd((int)str[i], fd);
		i++;
	}
	va_end(args);
	return (plen);
}
