/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:42:15 by swendum           #+#    #+#             */
/*   Updated: 2024/06/04 17:42:15 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_leftover(char *leftover)
{
	if (!leftover || *leftover == '\0')
	{
		free(leftover);
		leftover = NULL;
		return (leftover);
	}
	return (leftover);
}

int	searchend(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*getbuff(int fd, char *leftover, char *buffer)
{
	int		b;
	char	*temp;

	b = 1;
	temp = NULL;
	while (!(ft_strchr(leftover, '\n')) && b > 0)
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b == -1)
			return (free(buffer), buffer = NULL, NULL);
		buffer[b] = '\0';
		temp = leftover;
		leftover = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	free(buffer);
	buffer = NULL;
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	int			b;
	char		*buffer;
	char		*temp;

	buffer = (char *)malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buffer), free(leftover),
			buffer = NULL, leftover = NULL, NULL);
	if (!buffer)
		return (free (leftover), leftover = NULL, NULL);
	leftover = getbuff(fd, leftover, buffer);
	if (!leftover || *leftover == 0)
		return (free(leftover), leftover = NULL, NULL);
	b = searchend(leftover);
	buffer = ft_substr(leftover, 0, b);
	if (!buffer || *buffer == 0)
		return (free(buffer), free(leftover),
			buffer = NULL, leftover = NULL, NULL);
	temp = leftover;
	leftover = ft_substr(temp, b, ft_strlen(temp) - b);
	leftover = free_leftover(leftover);
	return (free(temp), temp = NULL, buffer);
}
