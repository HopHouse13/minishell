/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:55:05 by swendum           #+#    #+#             */
/*   Updated: 2024/06/02 15:55:05 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ispresent(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*copy(char *new, const char *s1, size_t start, size_t end)
{
	int	i;

	i = 0;
	while (start <= end)
		new[i++] = s1[start++];
	new[i] = '\0';
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*new;

	len = ft_strlen(s1);
	if (s1[0] == 0)
		return (ft_calloc(1, sizeof(char)));
	start = 0;
	while (ispresent(s1[start], set) && start < len - 1)
		start++;
	end = len - 1;
	while (ispresent(s1[end], set) && end > 0)
		end--;
	if (start > end)
		return (ft_calloc(1, sizeof(char)));
	new = malloc((end - start + 2) * sizeof(char));
	if (!new)
		return (NULL);
	new = copy(new, s1, start, end);
	return (new);
}
