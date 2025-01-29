/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:08:11 by swendum           #+#    #+#             */
/*   Updated: 2025/01/29 16:11:38 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**extract_exe_only(t_data *data, int i, int u, int j)
{
	char	**exe;

	if (i == -1)
		return (NULL);
	while (data->token[i + u] && data->token[i + u] != 'P')
		u++;
	exe = ft_calloc((u + 1), sizeof(char *));
	if (!exe)
		return (NULL);
	while (j < u && data->cmd[i + j] && data->token[i + j] != 'P')
	{
		if (data->token[i + j] == 'U' || data->token[i + j] == 'X'
			|| data->token[i + j] == 'W' || data->token[i + j] == 'D'
			|| data->token[i + j] == 'V' || data->token[i + j] == 'B')
		{
			exe[j] = ft_strdup(data->cmd[i + j]);
			if (!exe[j])
				return (free_tab(exe), NULL);
			j++;
		}
		else
			i++;
	}
	return (exe);
}

void	wait_children(t_data *data)
{
	int	i;
	int	p;

	i = 0;
	p = count_pipes(data);
	while (i <= p)
	{
		waitpid(data->id[i], &data->status, 0);
		if (WIFEXITED(data->status))
			data->status = WEXITSTATUS(data->status);
		else if (WIFSIGNALED(data->status))
			data->status = g_sig;
		i++;
	}
}

int	is_empty(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line [i] != ' ' && line[i] != '	' && line[i] != '\n')
			return (0);
	}
	return (1);
}

char	**mini_split(char *str, int i, int u)
{
	char	**split;

	while (str[i] && str[i] != '=')
		i++;
	while (str[i + u])
		u++;
	if (u)
		split = ft_calloc(3, sizeof(str));
	else
		split = ft_calloc(2, sizeof(str));
	if (!split)
		return (NULL);
	split[0] = malloc((i + 1) * sizeof(char));
	if (!split[0])
		return (free(split), NULL);
	ft_strlcpy(split[0], str, ++i);
	if (!u)
		return (split);
	split[1] = malloc((u + 1) * sizeof(char));
	if (!split[1])
		return (free(split[1]), free(split), NULL);
	ft_strlcpy(split[1], str + i, u + 1);
	return (split);
}
