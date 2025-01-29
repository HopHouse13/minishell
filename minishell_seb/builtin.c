/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:19:19 by swendum           #+#    #+#             */
/*   Updated: 2025/01/17 22:46:26 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_env_index(char **env, char *str)
{
	int	i;
	int	l;

	i = 0;
	if (!str)
		return (-1);
	l = ft_strlen(str);
	while (env[i])
	{
		if (!ft_strncmp(str, (const char *)env[i], l) && (env[i][l] == '='
			|| env[i][l] == 0))
			return (i);
		i++;
	}
	return (-1);
}

int	add_env(t_data *data, char *str)
{
	int		i;
	char	**new_env;

	i = 0;
	while (data->env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (0);
	i = -1;
	while (data->env[++i])
		new_env[i] = data->env[i];
	new_env[i] = str;
	new_env[++i] = 0;
	free(data->env);
	data->env = new_env;
	return (1);
}

void	replace_paths(t_data *data, char *newpath, char *path, int in)
{
	char	*abspath;
	char	*temp;

	in = get_env_index(data->env, "OLDPWD");
	if (in == -1)
		add_env(data, path);
	else
	{
		free(data->env[in]);
		data->env[in] = path;
	}
	in = get_env_index(data->env, "PWD");
	if (in == -1)
		add_env(data, newpath);
	else
	{
		free(data->env[in]);
		data->env[in] = newpath;
	}
	temp = getcwd(NULL, 0);
	abspath = ft_strjoin("PWD=", temp);
	in = get_env_index(data->env, "PWD");
	free(data->env[in]);
	data->env[in] = abspath;
	free(temp);
}

int	do_the_cd(char **cmd, t_data *data, char *newpath, char *temp)
{
	char	*path;

	newpath = (cmd[1]);
	if (cmd[1] && cmd[2])
		return (free(temp), ft_putstr_fd("cd: too many arguments\n", 2), 1);
	else if (!cmd[1])
	{
		newpath = get_env(data->env, "HOME");
		if (!newpath)
			return (free(temp), ft_putstr_fd("cd: HOME not set\n", 2), 1);
	}
	else if (!ft_strncmp(cmd[1], "-", ft_strlen(cmd[1])))
	{
		newpath = get_env(data->env, "OLDPWD");
		if (!newpath)
			return (free(temp), ft_putstr_fd("cd: OLDPWD not set\n", 2), 1);
		ft_printfd(1, "%s\n", newpath);
	}
	path = ft_strjoin("OLDPWD=", temp);
	if (chdir(newpath) != 0)
		return (perror("cd"), free(temp), free(path), 1);
	free(temp);
	temp = getcwd(NULL, 0);
	newpath = ft_strjoin("PWD=", temp);
	return (free(temp), replace_paths(data, newpath, path, 0), 0);
}

int	do_the_echo(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[++i])
	{
		if (!(i == 1 && !ft_strncmp(cmd[i], "-n", 3)))
		{
			ft_putstr_fd(cmd[i], 1);
			if (cmd[i + 1])
				ft_putchar_fd(' ', 1);
		}
	}
	if (!cmd[1] || ft_strncmp(cmd[1], "-n", 3))
		ft_putchar_fd('\n', 1);
	return (0);
}
