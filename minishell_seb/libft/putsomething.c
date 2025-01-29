/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsomething.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:32:34 by swendum           #+#    #+#             */
/*   Updated: 2024/11/12 00:42:18 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putcharfd(char a, int fd)
{
	write(fd, &a, 1);
	return (1);
}

size_t	ft_putstrfd(char *str, int fd)
{
	size_t	i;

	i = 0;
	if (!str)
		return (write(fd, "(null)", 6));
	while (str[i])
		ft_putcharfd(str[i++], fd);
	return (i);
}

size_t	ft_putintfd(int n, size_t i, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putcharfd('-', fd);
		i++;
		n = n * -1;
	}
	if (n >= 10)
		i = (ft_putintfd(n / 10, i, fd));
	ft_putcharfd((n % 10) + 48, fd);
	return (++i);
}

size_t	ft_putuintfd(unsigned int n, size_t i, int fd)
{
	if (n >= 10)
		i = (ft_putuintfd(n / 10, i, fd));
	ft_putcharfd((int)(n % 10) + 48, fd);
	return (++i);
}

size_t	ft_puthexafd(unsigned int n, const char c, size_t i, int fd)
{
	char	*hex;

	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		i = (ft_puthexafd(n / 16, c, i, fd));
	ft_putcharfd(hex[n % 16], fd);
	return (++i);
}
