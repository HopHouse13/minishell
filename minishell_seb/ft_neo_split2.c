/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neo_split2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:13:52 by swendum           #+#    #+#             */
/*   Updated: 2025/01/10 17:24:58 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	subfilltab(t_data *data, const char *s, t_monke *m, size_t *i)
{
	if (s[*i] != '\'' && s[*i] != '\"')
	{
		m->c = m->j;
		while (s[*i] && s[*i] != ' ' && s[*i] != '	'
			&& s[*i] != '\'' && s[*i] != '\"')
			data->cmd[m->w][m->j++] = s[(*i)++];
		m->j = change_cash(data, m->c, m->w, s + *i);
	}
	else
	{
		m->c = m->j;
		m->t = (*i)++;
		while (s[*i] && s[*i] != s[m->t])
			data->cmd[m->w][m->j++] = s[(*i)++];
		if (s[*i])
			(*i)++;
		if (s[m->t] == '\"')
		{
			m->j = change_cash(data, m->c, m->w, s + *i);
			data->token[m->w] = 'W';
		}
		else if (s[m->t] == '\'')
			data->token[m->w] = 'V';
	}
}

void	neofilltab(const char *s, t_data *data, size_t i)
{
	t_monke	m;

	m.w = 0;
	while (s[i])
	{
		m.j = 0;
		if (s[i] && s[i] != ' ' && s[i] != '	')
		{
			while (s[i] && s[i] != ' ' && s[i] != '	')
			{
				subfilltab(data, s, &m, &i);
			}
			if (!data->token[m.w])
				data->token[m.w] = 'U';
			m.w++;
		}
		if (!s[i])
			return ;
		i++;
	}
}
