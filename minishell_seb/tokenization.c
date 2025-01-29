/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:18:06 by swendum           #+#    #+#             */
/*   Updated: 2025/01/21 02:55:31 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "cd", 3) || !ft_strncmp(cmd, "echo", 5)
		|| !ft_strncmp(cmd, "pwd", 4) || !ft_strncmp(cmd, "export", 7)
		|| !ft_strncmp(cmd, "unset", 6) || !ft_strncmp(cmd, "env", 4)
		|| !ft_strncmp(cmd, "exit", 5))
		return (1);
	return (0);
}

int	check_exec(char *cmd, char *path)
{
	char	**split_path;
	int		i;
	char	*temp;
	char	*exe;

	if (access(cmd, F_OK | X_OK) == 0 && ft_strchr(cmd, '/'))
		return (1);
	split_path = ft_split((const char *)path, ':');
	if (!split_path)
		return (0);
	i = 0;
	while (split_path[i])
	{
		temp = ft_strjoin(split_path[i], "/");
		exe = ft_strjoin(temp, cmd);
		free(temp);
		if (access(exe, F_OK | X_OK) == 0)
			return (free_tab(split_path), free(exe), 1);
		free(exe);
		i++;
	}
	return (free_tab(split_path), 0);
}

int	sub_token(t_data *data, int i, int *b)
{
	if ((!ft_strncmp(data->cmd[i], ">", 2)
			|| !ft_strncmp(data->cmd[i], "<", 2)
			|| !ft_strncmp(data->cmd[i], "<<", 3)
			|| !ft_strncmp(data->cmd[i], ">>", 3))
		&& data->token[i] != 'W' && data->token[i] != 'V')
		data->token[i] = 'R';
	if (!ft_strncmp(data->cmd[i], ">", 2) && data->cmd[i + 1])
		data->token[++i] = 'O';
	else if (!ft_strncmp(data->cmd[i], "<", 2) && data->cmd[i + 1])
		data->token[++i] = 'I';
	else if (!ft_strncmp(data->cmd[i], "<<", 3) && data->cmd[i + 1])
		data->token[++i] = 'H';
	else if (!ft_strncmp(data->cmd[i], ">>", 3) && data->cmd[i + 1])
		data->token[++i] = 'C';
	else if (check_builtin(data->cmd[i]) && *b)
	{
		data->token[i] = 'B';
		*b = 0;
	}
	else if (check_exec(data->cmd[i], get_env(data->env, "PATH")) && *b)
	{
		data->token[i] = 'X';
		*b = 0;
	}
	return (i);
}

void	clean_redirection(t_data *data, int i, int c, int u)
{
	if ((data->token[i] == 'C' && !ft_strncmp(data->cmd[i], ">>", 2))
		|| (data->token[i] == 'H' && !ft_strncmp(data->cmd[i], "<<", 2)))
		c = 2;
	else if ((data->token[i] == 'O' && !ft_strncmp(data->cmd[i], ">", 1))
		|| (data->token[i] == 'I' && !ft_strncmp(data->cmd[i], "<", 1)))
		c = 1;
	if (!c)
		return ;
	while (data->cmd[i][c])
		data->cmd[i][u++] = data->cmd[i][c++];
	data->cmd[i][u] = 0;
	if (data->token[i] == 'C' || data->token[i] == 'H')
		data->cmd[i][++u] = 0;
}

void	tokenisation(t_data *data, int i, int b)
{
	while (data->cmd[++i])
	{
		i = sub_token(data, i, &b);
		if (!data->cmd[i])
			break ;
		if (data->token[i] == 'U' && !ft_strncmp(data->cmd[i], ">>", 2))
			data->token[i] = 'C';
		else if (data->token[i] == 'U' && !ft_strncmp(data->cmd[i], "<<", 2))
			data->token[i] = 'H';
		else if (data->token[i] == 'U' && !ft_strncmp(data->cmd[i], ">", 1))
			data->token[i] = 'O';
		else if (data->token[i] == 'U' && !ft_strncmp(data->cmd[i], "<", 1))
			data->token[i] = 'I';
		else if (data->cmd[i] && !ft_strncmp(data->cmd[i], "|", 2))
		{
			data->token[i] = 'P';
			b = 1;
		}
		else if (data->cmd[i] && opendir(data->cmd[i]))
			data->token[i] = 'D';
		clean_redirection(data, i, 0, 0);
	}
}
