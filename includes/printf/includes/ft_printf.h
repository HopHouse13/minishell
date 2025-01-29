/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:08:26 by pbret             #+#    #+#             */
/*   Updated: 2024/07/08 15:22:57 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putchar_count(int c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(long nb, const char *type, int i, int *count);
void	ft_conver(va_list args, const char *type, int i, int *count);
void	ft_putnbr_base(unsigned long valeur, const char *type, int i,
			int *count);
void	ft_flags(const char *str, int i, int *count);

int		ft_gestion_zero(unsigned long valeur, char const *str, int i,
			int *count);
int		ft_printf(const char *str, ...);

#endif