/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 23:40:54 by swendum           #+#    #+#             */
/*   Updated: 2025/01/29 12:58:48 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char **env, char *str)
{
	int	i;
	int	l;

	i = 0;
	if (!str)
		return (NULL);
	l = ft_strlen(str);
	while (env[i])
	{
		if (!ft_strncmp(str, (const char *)env[i], l) && env[i][l] == '=')
			return (env[i] + l + 1);
		i++;
	}
	return (NULL);
}

t_data	*create_data(char **env, int i)
{
	t_data	*data;

	g_sig = 1;
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	while (env[i])
		i++;
	data->env = ft_calloc((i + 1), sizeof(char *));
	if (!data->env)
		return (free(data), NULL);
	i = -1;
	while (env[++i])
	{
		data->env[i] = ft_strdup(env[i]);
		if (!data->env[i])  
			return (free_tab(data->env), free(data), NULL);
	}
	data->pfd = NULL;
	data->id = NULL;
	data->cmd = NULL;
	data->token = NULL;
	data->status = 0;
	return (data->expension = 0, data->heredoc = 0, data);
}

int	clean_data(t_data *data, int i, char *file, char *temp)
{
	(void) i;
	(void) file;
	(void) temp;
	if (data->cmd)
		free_tab(data->cmd);
	if (data->id)
		free(data->id);
	if (data->pfd)
		free(data->pfd);
	if (data->token)
		free(data->token);
	if (data->env)
		free_tab(data->env);
	rl_clear_history();
	data->cmd = NULL;
	data->id = NULL;
	data->pfd = NULL;
	data->token = NULL;
	data->env = NULL;
	return (free(data), data = NULL, 1);
}

int	reboot_data(t_data *data, int i, char *file, char *temp)
{
	while (data->cmd && data->cmd[++i])
	{
		temp = ft_itoa(i);
		file = ft_strjoin("temp", temp);
		unlink(file);
		free(temp);
		free(file);
	}
	if (data->cmd)
	{
		if (data->id)
			free(data->id);
		if (data->pfd)
			free(data->pfd);
		free_tab(data->cmd);
		data->cmd = NULL;
		data->id = NULL;
		data->pfd = NULL;
	}
	if (data->token)
	{
		free(data->token);
		data->token = NULL;
	}
	return (data->expension = 0, g_sig = 1, dup2(0, 0), dup2(1, 1), 1);
}
