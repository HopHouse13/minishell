/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neo_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:15:21 by swendum           #+#    #+#             */
/*   Updated: 2025/01/16 16:38:29 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned char	ifskiptonext(const char *s, size_t i, size_t *j)
{
	int	t;

	t = *j;
	if (s[i + *j] == '\'' || s[i + *j] == '\"')
	{
		(*j)++;
		while (s[i + *j] && s[i + *j] != s[i + t])
			(*j)++;
		if (s[i + *j])
			(*j)++;
		return (1);
	}
	return (0);
}

size_t	neocountwords(const char *s, size_t i)
{
	size_t			words;
	unsigned char	bol;

	bol = 1;
	words = 0;
	while (s[i])
	{
		if (bol && s[i] != ' ' && s[i] != '	')
		{
			if (ifskiptonext(s, 0, &i))
				i--;
			words++;
			bol = 0;
		}
		else if (s[i] == ' ' || s[i] == '	')
			bol = 1;
		i++;
		if (!bol && (s[i] == '\'' || s[i] == '\"'))
			ifskiptonext(s, 0, &i);
	}
	return (words);
}

int	change_cash(t_data *data, int c, int w, const char *s)
{
	char	*temp;

	while (data->cmd[w][c] && data->cmd[w][c] != '$')
		c++;
	if (!data->cmd[w][c])
		return (ft_strlen(data->cmd[w]));
	if (!grand_remplaced(data, w, data->cmd[w] + c, c))
		return (change_cash(data, c + 1, w, s));
	temp = ft_calloc(sizeof(char),
			(ft_strlen(data->cmd[w]) + ft_strlen(s) + 1));
	ft_strlcpy(temp, data->cmd[w], ft_strlen(data->cmd[w]) + 1);
	free(data->cmd[w]);
	data->cmd[w] = temp;
	return (change_cash(data, c, w, s));
}

int	neocreatetabs(const char *s, t_data *data, size_t i, size_t w)
{
	t_monke	m;

	m.bol = 1;
	while (s && s[++i])
	{
		m.j = 0;
		m.quotes = 0;
		if (m.bol && s[i] && s[i] != ' ' && s[i] != '	')
		{
			while (s[i + m.j] && s[i + m.j] != ' ' && s[i + m.j] != '	')
			{
				if (ifskiptonext(s, i, &m.j))
					m.quotes += 2;
				else
					m.j++;
			}
			data->cmd[w] = ft_calloc((m.j + 1 - m.quotes), sizeof(char));
			if (clean(data->cmd, w++) && m.bol--)
				return (0);
			i += (m.j - 1);
		}
		if (s[i] && (s[i] == ' ' || s[i] == '	'))
			m.bol = 1;
	}
	return (neofilltab(s, data, 0), 1);
}

int	ft_neosplit(const char *s, t_data *data)
{
	size_t	words;

	if (!s)
		return (0);
	words = neocountwords(s, 0);
	if (!words)
		return (0);
	data->cmd = malloc((words + 1) * sizeof(char *));
	if (!data->cmd)
		return (0);
	data->token = ft_calloc((words + 1), sizeof(char));
	if (!data->token)
		return (free(data->cmd), 0);
	if (neocreatetabs(s, data, -1, 0) == 0)
		return (free(data->cmd), free(data->token), 0);
	data->cmd[words] = NULL;
	data->token[words] = 0;
	return (1);
}
