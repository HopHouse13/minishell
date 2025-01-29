/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:53:44 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:59:17 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*ft_flags gene les 3 flags: '#''space''+'
>	'#': utilise avec les valeurs octales et hexadecimales.
si Flag -> prefixe '0' ou '0x' (%x%X%o)
>	'space': Insère un espace avant les nombres positifs (%d%i)
>	'+': Affiche toujours le signe pour les entiers (positif ou négatif)(%d%i)
*/
void	ft_flags(const char *str, int i, int *count)
{
	if (str[i -1] == '+' && str[i -2] == '%')
		ft_putchar_count('+', count);
	if (str[i -1] == ' ' && str[i -2] == '%')
		ft_putchar_count(' ', count);
	if (((str[i -1] == '#' && str[i -2] == '%') && (str[i] == 'x'
				|| str[i] == 'p')) || (str[i -1] == '%' && str[i] == 'p'))
		ft_putstr("0x", count);
	if (((str[i -1] == '#' && str[i -2] == '%')) && str[i] == 'X')
		ft_putstr("0X", count);
	if (str[i -2] == '%' && str[i -1] == '#' && str[i] == 'o')
		ft_putchar_count('0', count);
}

int	ft_gestion_zero(unsigned long valeur, char const *str, int i, int *count)
{
	if (valeur == 0)
	{
		if (str[i] == 'p')
			ft_putstr("(nil)", count);
		else
			ft_putchar_count('0', count);
		return (1);
	}
	return (0);
}

void	ft_putnbr(long nb, const char *str, int i, int *count)
{
	char	resul[12];
	int		k;

	if (nb >= 0)
		ft_flags(str, i, count);
	if (nb == 0)
	{
		ft_putchar_count('0', count);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_count('-', count);
		nb = nb * -1;
	}
	k = 11;
	resul[k] = '\0';
	while (nb > 0)
	{
		resul[--k] = (nb % 10) + '0';
		nb /= 10;
	}
	while (resul[k])
		ft_putchar_count(resul[k++], count);
}

void	ft_putnbr_base(unsigned long valeur,
			const char *str, int i, int *count)
{
	char	*base_hexa;
	char	resul[18];
	int		k;
	int		base;

	base = 16;
	base_hexa = "0123456789abcdef";
	if (ft_gestion_zero(valeur, str, i, count))
		return ;
	ft_flags(str, i, count);
	if ((str[i -1] == '%' || str[i -2] == '%') && (str[i] == 'o'))
		base = 8;
	k = 17;
	resul[k] = '\0';
	if (str[i] == 'X')
		base_hexa = "0123456789ABCDEF";
	while (valeur)
	{
		resul[--k] = base_hexa[valeur % base];
		valeur /= base;
	}
	while (resul[k])
		ft_putchar_count(resul[k++], count);
}
