/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:05:58 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:45:22 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*Fonctionnement de la macro va_arg :
>	Gestion des arguments au nombre indefini. Ces arguments se trouvent
dans la signature de la fonction et sont representes par " ... "
>	Creation du struct nommee "args" de type "va_list":La totalite des args 
sont stocker dans cette struct.
>	"va_start" serre a initialiser(demarrer) la struct"va_list"(arguments)+str
>	A chaque fois que la struct va_args est appelee, l'arg suivant est appele,
traite. Puis la prochaine fois que la struct va_args est appelee, l'arg suivant
sera appele, traite. etc
>	A la fin du programme, "va_end" serre a liberer les ressources utilisent 
pour parcourir les args. En gros -> "on a fini de bosser avec, tu peux stopper
 ton processus avec cette macro"*/
void	ft_conver(va_list args, const char *str, int i, int *count)
{
	if (str[i] == 'c')
		ft_putchar_count(va_arg(args, int), count);
	else if (str[i] == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(va_arg(args, int), str, i, count);
	else if (str[i] == 'u')
		ft_putnbr(va_arg(args, unsigned int), str, i, count);
	else if (str[i] == 'X' || str[i] == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), str, i, count);
	else if (str[i] == 'p' || str[i] == 'o')
		ft_putnbr_base(va_arg(args, unsigned long), str, i, count);
	else if (str[i] == '%')
		ft_putchar_count('%', count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if ((str[i] == '#' || str[i] == '+' || str[i] == ' ')
				&& str[i -1] == '%')
				i++;
			ft_conver(args, str, i, &count);
		}
		else
			ft_putchar_count(str[i], &count);
		i++;
	}
	return (count);
	va_end (args);
}
