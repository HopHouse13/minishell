/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trade_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:28:59 by swendum           #+#    #+#             */
/*   Updated: 2025/01/27 15:13:04 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sub_remplaced(t_data *data, t_monke *m, char **u, char *temp)
{
	char	*new;

	new = ft_calloc(sizeof(char), (ft_strlen(*u) + 1));
	while ((*u)[m->p + 1] && (ft_isalnum((*u)[m->p + 1])
		|| ((m->p + 1) == 1 && ((*u)[m->p + 1] == '_'
		|| (*u)[m->p + 1] == '?'))))
	{
		new[m->p] = (*u)[m->p + 1];
		if (!ft_strncmp(new, "?", ft_strlen(new)))
			break ;
		m->p++;
	}
	if (new[0] == 0)
		return (free(new), 0);
	if (!ft_strncmp(new, "?", ft_strlen(new)))
	{
		temp = ft_itoa(data->status);
		*u = ft_strjoin(temp, new + 1);
		return (free(temp), free(new), 1);
	}
	temp = get_env(data->env, new);
	*u = NULL;
	if (temp)
		*u = ft_strdup(temp);
	return (free(new), 1);
}

void	grand_remplaced2(char *cmd, int c, char **new, char **u)
{
	t_monke	m;

	m.p = 0;
	while ((cmd[m.p] && cmd[m.p] != '$') || m.p < c)
	{
		(*new)[m.p] = cmd[m.p];
		m.p++;
	}
	m.d = 0;
	while (*u && (*u)[m.d])
	{
		(*new)[m.p + m.d] = (*u)[m.d];
		m.d++;
	}
	m.s = 1;
	while (cmd[m.p + m.s] && (ft_isalnum(cmd[m.p + m.s])
			|| (cmd[m.p + m.s -1] == '$' && cmd[m.p + m.s] == '_')))
		m.s++;
	if (cmd[m.p + m.s -1] == '$' && cmd[m.p + m.s] == '?')
		m.s++;
	while (cmd[m.p + m.s])
	{
		(*new)[m.p + m.d] = cmd[m.p + m.s];
		m.p++;
	}
}

int	grand_remplaced(t_data *data, int i, char *u, int c)
{
	char	*new;
	t_monke	m;

	m.p = 0;
	if (!sub_remplaced(data, &m, &u, NULL))
		return (0);
	if (u)
		new = ft_calloc(sizeof(char),
				(ft_strlen(data->cmd[i]) - m.p + ft_strlen(u) + 1));
	else
		new = ft_calloc(sizeof(char), (ft_strlen(data->cmd[i]) - m.p + 1));
	if (!new)
		return (0);
	grand_remplaced2(data->cmd[i], c, &new, &u);
	if (u)
		free(u);
	return (free(data->cmd[i]), data->cmd[i] = new, 1);
}
